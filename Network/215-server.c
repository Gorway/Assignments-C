#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/wait.h>

#define PORT 12345
#define BUFFER_SIZE 1024

void handle_client(int client_socket) {
    char buffer[BUFFER_SIZE];
    ssize_t bytes_received;

    while ((bytes_received = recv(client_socket, buffer, BUFFER_SIZE, 0)) > 0) {
        buffer[bytes_received] = '\0';
        printf("Message from client: %s", buffer);
        // Echo message back to client
        send(client_socket, buffer, strlen(buffer), 0);
    }

    if (bytes_received == 0) {
        printf("Client disconnected\n");
    } else {
        perror("Error receiving message from client");
    }

    close(client_socket);
}

int main() {
    int server_socket, client_socket;
    struct sockaddr_in server_address, client_address;
    socklen_t client_address_length = sizeof(client_address);
    pid_t child_pid;

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
    if (listen(server_socket, 10) < 0) {
        perror("Error listening for connections");
        exit(EXIT_FAILURE);
    }

    printf("Multi-process TCP server is running. Waiting for connections...\n");

    // Accept incoming connections and handle each in a separate process
    while (1) {
        client_socket = accept(server_socket, (struct sockaddr *)&client_address, &client_address_length);
        if (client_socket < 0) {
            perror("Error accepting connection");
            exit(EXIT_FAILURE);
        }

        child_pid = fork();
        if (child_pid == 0) {
            // Child process
            close(server_socket); // Close server socket in child process
            handle_client(client_socket);
            exit(EXIT_SUCCESS); // Exit child process
        } else if (child_pid < 0) {
            perror("Error forking process");
            exit(EXIT_FAILURE);
        } else {
            // Parent process
            close(client_socket); // Close client socket in parent process
            waitpid(-1, NULL, WNOHANG); // Clean up terminated child processes
        }
    }

    // Close server socket
    close(server_socket);

    return 0;
}

