#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <pthread.h>

#define PORT 12345
#define BUFFER_SIZE 1024

void *handle_client(void *arg) {
    int client_socket = *((int *)arg);
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
    free(arg);
    pthread_exit(NULL);
}

int main() {
    int server_socket, client_socket;
    struct sockaddr_in server_address, client_address;
    socklen_t client_address_length = sizeof(client_address);
    pthread_t tid;

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

    printf("Multi-threaded TCP server is running. Waiting for connections...\n");

    // Accept incoming connections and create thread for each client
    while (1) {
        client_socket = accept(server_socket, (struct sockaddr *)&client_address, &client_address_length);
        if (client_socket < 0) {
            perror("Error accepting connection");
            exit(EXIT_FAILURE);
        }

        int *client_socket_ptr = malloc(sizeof(int));
        if (client_socket_ptr == NULL) {
            perror("Error allocating memory for client socket pointer");
            exit(EXIT_FAILURE);
        }
        *client_socket_ptr = client_socket;

        if (pthread_create(&tid, NULL, handle_client, (void *)client_socket_ptr) != 0) {
            perror("Error creating thread");
            exit(EXIT_FAILURE);
        }

        // Detach thread to avoid memory leaks
        pthread_detach(tid);
    }

    // Close server socket
    close(server_socket);

    return 0;
}

