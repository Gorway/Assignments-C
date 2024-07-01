#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>

#define SERVER_IP "127.0.0.1"
#define PORT 12345
#define BUFFER_SIZE 1024
#define EXIT_MESSAGE "exit"

int main() {
    
    int client_socket;
    struct sockaddr_in server_addr;
    char buffer[BUFFER_SIZE] = {0};
    int number;

    client_socket = socket(AF_INET, SOCK_DGRAM, 0);

    memset(&server_addr, 0, sizeof(server_addr));

    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = inet_addr(SERVER_IP);
    server_addr.sin_port = htons(PORT);

    printf("Enter number: ");
    scanf("%d", &number);

    snprintf(buffer, BUFFER_SIZE, "%d", number);

    sendto(client_socket, buffer, BUFFER_SIZE, 0, (struct
    sockaddr*)&server_addr, sizeof(server_addr));

    printf("Number %d sent to server\n", number);

    ssize_t  bytes_received = recvfrom(client_socket, buffer, BUFFER_SIZE, 0,
    NULL, NULL);

    buffer[bytes_received] = '\0';

    printf("Square received from server: %s\n", buffer);

    close(client_socket);
}


    


