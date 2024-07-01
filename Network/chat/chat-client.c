#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define PORT 8080
#define BUFFER_SIZE 1024

int main() {
    int sock = 0;
    struct sockaddr_in serv_addr;
    char buffer[BUFFER_SIZE] = {0};

    // Создание клиентского сокета
    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("socket creation error");
        return -1;
    }

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);

    // Преобразование IP адреса из текста в бинарный формат
    if (inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr) <= 0) {
        perror("invalid address / address not supported");
        return -1;
    }

    // Установление соединения с сервером
    if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        perror("connection failed");
        return -1;
    }

    while (1) {
        printf("Enter message for server: ");
        fgets(buffer, BUFFER_SIZE, stdin);
        send(sock, buffer, strlen(buffer), 0);
        int valread = read(sock, buffer, BUFFER_SIZE);
        printf("Server: %s", buffer);
    }

    close(sock);
    return 0;
}

