#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define SERVER_IP "127.0.0.1"
#define SERVER_PORT 8888
#define BUFFER_SIZE 1024

int main() {
    int client_socket;
    struct sockaddr_in server_addr;
    char message[BUFFER_SIZE];
    char server_reply[BUFFER_SIZE];

    // Создание TCP сокета
    client_socket = socket(AF_INET, SOCK_STREAM, 0);

    // Настройка структуры server_addr
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = inet_addr(SERVER_IP);
    server_addr.sin_port = htons(SERVER_PORT);

    // Подключение к серверу
    connect(client_socket, (struct sockaddr *)&server_addr, sizeof(server_addr));

    // Отправка сообщения на сервер
    printf("Введите сообщение для отправки на сервер: ");
    fgets(message, BUFFER_SIZE, stdin);
    send(client_socket, message, strlen(message), 0);

    // Получение ответа от сервера
    recv(client_socket, server_reply, BUFFER_SIZE, 0);
    printf("Ответ от сервера: %s\n", server_reply);

    // Закрытие сокета
    close(client_socket);

    return 0;
}

