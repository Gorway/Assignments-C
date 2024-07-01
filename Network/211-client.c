#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <string.h>

#define BUFFER_SIZE 1024
#define PORT 12345
#define SERVER_IP "127.0.0.1"
int main() {

    int client_socket;
    struct sockaddr_in server_addr;
    char buffer[BUFFER_SIZE];

    memset(&server_addr, 0, sizeof(server_addr));

    client_socket = socket(AF_INET, SOCK_STREAM, 0);
    if(client_socket == - 1) {
        perror("Error creating socket");
        exit(EXIT_FAILURE);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = inet_addr(SERVER_IP);
    server_addr.sin_port = htons(PORT);

    if(connect(client_socket,(struct sockaddr*)&server_addr,
        sizeof(server_addr)) < 0) {
        perror("Error  conecting to server");
        exit(EXIT_FAILURE);
    }
    
    printf("Connected to server\n");

    ssize_t bytes_received = recv(client_socket, buffer, sizeof(buffer), 0);
    if(bytes_received < 0) {
        perror("Error receiving message from server");
        exit(EXIT_FAILURE);
    }

    printf("Message from server: %.*s", (int)bytes_received,buffer);

    close(client_socket);
}



