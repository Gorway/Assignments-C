#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT 12345

typedef struct {
    size_t size;
    char i_name[256];
    uint8_t i_status;
    uint8_t i_type;
} Open;

int main() {
    int client_socket;
    struct sockaddr_in server_address;

    // Create client socket
    client_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (client_socket == -1) {
        perror("Error creating client socket");
        exit(EXIT_FAILURE);
    }

    // Set server address
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = inet_addr("127.0.0.1"); // IP адрес сервера
    server_address.sin_port = htons(PORT);

    // Connect to server
    if (connect(client_socket, (struct sockaddr *)&server_address, sizeof(server_address)) < 0) {
        perror("Error connecting to server");
        exit(EXIT_FAILURE);
    }

    printf("Connected to server\n");

    // Send command "open" to server
    char command[] = "open";
    if (send(client_socket, command, strlen(command), 0) < 0) {
        perror("Error sending command to server");
        close(client_socket);
        exit(EXIT_FAILURE);
    }

    // Receive Open structure from server
    Open open;
    ssize_t bytes_received = recv(client_socket, &open, sizeof(Open), 0);
    if (bytes_received != sizeof(Open)) {
        perror("Error receiving data from server");
        close(client_socket);
        exit(EXIT_FAILURE);
    }

    // Print received data
    printf("Received data from server:\n");
    printf("Size: %zu\n", open.size);
    printf("Name: %s\n", open.i_name);
    printf("Status: %hhu\n", open.i_status);
    printf("Type: %hhu\n", open.i_type);

    // Receive open count from server
    int open_count;
    bytes_received = recv(client_socket, &open_count, sizeof(open_count), 0);
    if (bytes_received != sizeof(open_count)) {
        perror("Error receiving data from server");
        close(client_socket);
        exit(EXIT_FAILURE);
    }

    // Print open count
    printf("Number of open objects: %d\n", open_count);

    // Close client socket
    close(client_socket);

    return 0;
}

