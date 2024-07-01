#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/socket.h>
#include <string.h>
#include <arpa/inet.h>

#define PORT 8080
#define BUFFER_SIZE 1024
#define FILE_NAME "file"
int main() {

    int sock = 0;
    struct sockaddr_in serv_addr;
    char buffer[BUFFER_SIZE] = {0};
    char file_name[BUFFER_SIZE];


    sock = socket(AF_INET, SOCK_STREAM, 0);

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);

    inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr);

    connect(sock, (struct sockaddr*)&serv_addr, sizeof(serv_addr));


    send(sock, FILE_NAME, strlen(FILE_NAME), 0);

    int bytes_reaceived = recv(sock, buffer, BUFFER_SIZE, 0);
    printf("File content recieved from server:\n%s\n", buffer);

    bytes_reaceived = recv(sock, buffer, BUFFER_SIZE, 0);
    printf("Additional information reveived from server:\n%s\n", buffer);

    close(sock);
    return 0;
}
