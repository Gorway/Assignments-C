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
    char command[BUFFER_SIZE];

    // Создание сокета
    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("socket creation failed");
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

    printf("Enter Linux command: ");
    fgets(command, BUFFER_SIZE, stdin);

    // Отправка команды серверу
    send(sock, command, strlen(command), 0);

    // Получение результатов выполнения команды от сервера
    int bytes_received;
    while ((bytes_received = recv(sock, buffer, BUFFER_SIZE, 0)) > 0) {
        printf("%s", buffer);
    }

    close(sock);
    return 0;
}

