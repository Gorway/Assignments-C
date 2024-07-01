#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>

#define PORT 12345
#define MAX_CLIENTS 10
#define BUFFER_SIZE 1024

int main() {
    int server_socket, client_sockets[MAX_CLIENTS];
    struct sockaddr_in server_address, client_address;
    socklen_t client_address_length = sizeof(client_address);
    char buffer[BUFFER_SIZE];

    // Create server socket
    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket == -1) {
        perror("Error creating server socket");
        exit(EXIT_FAILURE);
    }

    // Set server address
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = INADDR_ANY;
    server_address.sin_port = htons(PORT);

    // Bind socket to address and port
    if (bind(server_socket, (struct sockaddr *)&server_address, sizeof(server_address)) < 0) {
        perror("Error binding server socket");
        exit(EXIT_FAILURE);
    }

    // Listen for incoming connections
    if (listen(server_socket, MAX_CLIENTS) < 0) {
        perror("Error listening for connections");
        exit(EXIT_FAILURE);
    }

    printf("Chat server is running. Waiting for connections...\n");

    // Accept incoming connections and handle messages
    int num_clients = 0;
    while (1) {
        // Accept connection from client
        int client_socket = accept(server_socket, (struct sockaddr *)&client_address, &client_address_length);
        if (client_socket < 0) {
            perror("Error accepting connection");
            exit(EXIT_FAILURE);
        }

        // Add client socket to array
        if (num_clients < MAX_CLIENTS) {
            client_sockets[num_clients++] = client_socket;
            printf("Client connected: %s:%d\n", inet_ntoa(client_address.sin_addr), ntohs(client_address.sin_port));
        } else {
            printf("Maximum number of clients reached. Rejecting new connection.\n");
            close(client_socket);
            continue;
        }

        // Handle messages from client
        while (1) {
            ssize_t bytes_received = recv(client_socket, buffer, BUFFER_SIZE, 0);
            if (bytes_received < 0) {
                perror("Error receiving message from client");
                exit(EXIT_FAILURE);
            } else if (bytes_received == 0) {
                printf("Client disconnected\n");
                close(client_socket);
                break;
            } else {
                // Forward message to all clients except sender
                for (int i = 0; i < num_clients; i++) {
                    if (client_sockets[i] != client_socket) {
                        if (send(client_sockets[i], buffer, bytes_received, 0) < 0) {
                            perror("Error sending message to client");
                            exit(EXIT_FAILURE);
                        }
                    }
                }
            }
        }
    }

    // Close server socket
    close(server_socket);

    return 0;
}

