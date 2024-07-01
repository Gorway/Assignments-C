#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>

#define PORT 12345
#define BUFFER_SIZE 1024
#define EXIT_MESSAGE "exit"

int main() {

    int server_socket;
    struct sockaddr_in server_addr, client_addr;
    socklen_t client_address_length = sizeof(client_addr);
    char buffer[BUFFER_SIZE] = {0};

    server_socket = socket(AF_INET, SOCK_DGRAM, 0);


    memset(&server_addr, 0, sizeof(server_addr));

    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);

    bind(server_socket, (struct sockaddr*)&server_addr, sizeof(server_addr));
    
    printf("Server is running waiting for messages...\n");

    while(1) {

        ssize_t received_bytes = recvfrom(server_socket, buffer, BUFFER_SIZE, 0,
        (struct sockaddr*)&client_addr,(socklen_t*)&client_address_length);
        
        int number = atoi(buffer);
        int square = number * number;

        snprintf(buffer, BUFFER_SIZE, "%d", square);

        sendto(server_socket, buffer, strlen(buffer), 0, (struct sockaddr*)&client_addr, client_address_length);

        printf("Square of %d sent to client.\n", number);
    }
        close(server_socket);
}

