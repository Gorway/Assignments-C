#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 8080
#define BUFFER_SIZE 1024

int main() {
    int sock = 0, valread;
    struct sockaddr_in serv_addr;
    char *hello = "Привет, это сообщение от клиента!";
    char buffer[BUFFER_SIZE] = {0};

    // Создание сокета
    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        printf("\n Socket creation error \n");
        return -1;
    }

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);

    // Преобразование IP адреса из текстового формата в структуру
    if(inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr)<=0) {
        printf("\nInvalid address/ Address not supported \n");
        return -1;
    }

    // Подключение к серверу
    if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        printf("\nConnection Failed \n");
        return -1;
    }

    // Отправка сообщения серверу
    send(sock , hello , strlen(hello) , 0 );
    printf("Приветное сообщение отправлено\n");
    valread = read( sock , buffer, BUFFER_SIZE);
    printf("%s\n",buffer );
    return 0;
}

