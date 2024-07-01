#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>

#define PORT 12345
#define BUFFER_SIZE 1024

int main() {
    int client_socket;
    struct sockaddr_in server_address;
    char buffer[BUFFER_SIZE];

    // Create client socket
    client_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (client_socket == -1) {
        perror("Error creating client socket");
        exit(EXIT_FAILURE);
    }

    // Set server address
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = inet_addr("127.0.0.1");
    server_address.sin_port = htons(PORT);

    // Connect to server
    if (connect(client_socket, (struct sockaddr *)&server_address, sizeof(server_address)) < 0) {
        perror("Error connecting to server");
        exit(EXIT_FAILURE);
    }

    printf("Connected to server. Start typing your messages...\n");

    // Start sending and receiving messages
    while (1) {
        // Get message from user
        printf("Enter message: ");
        fgets(buffer, BUFFER_SIZE, stdin);

        // Send message to server
        if (send(client_socket, buffer, strlen(buffer), 0) < 0) {
            perror("Error sending message to server");
            exit(EXIT_FAILURE);
        }

        // Receive message from server
        ssize_t bytes_received = recv(client_socket, buffer, BUFFER_SIZE, 0);
        if (bytes_received < 0) {
            perror("Error receiving message from server");
            exit(EXIT_FAILURE);
        } else if (bytes_received == 0) {
            printf("Server disconnected\n");
            break;
        } else {
            buffer[bytes_received] = '\0';
            printf("Message from server: %s", buffer);
        }
    }

    // Close client socket
    close(client_socket);

    return 0;
}

