#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define SERVER_IP "127.0.0.1"
#define PORT 8888
#define BUFFER_SIZE 1024

int main() {
    int client_socket;
    struct sockaddr_in server_addr;
    char buffer[BUFFER_SIZE];
    int recv_len;

    // Создание TCP сокета
    client_socket = socket(AF_INET, SOCK_STREAM, 0);

    // Настройка структуры server_addr
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = inet_addr(SERVER_IP);
    server_addr.sin_port = htons(PORT);

    // Подключение к серверу
    if (connect(client_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Ошибка подключения");
        return 1;
    }

    // Получение имени пользователя
    char username[BUFFER_SIZE];
    printf("Введите ваше имя: ");
    fgets(username, BUFFER_SIZE, stdin);
    username[strcspn(username, "\n")] = 0; // Удаление символа новой строки

    // Отправка имени пользователя на сервер
    send(client_socket, username, strlen(username), 0);

    // Цикл обработки сообщений
    while (1) {
        // Ввод сообщения от пользователя
        printf("Введите сообщение: ");
        fgets(buffer, BUFFER_SIZE, stdin);
        buffer[strcspn(buffer, "\n")] = 0; // Удаление символа новой строки

        // Отправка сообщения на сервер
        send(client_socket, buffer, strlen(buffer), 0);

        // Получение ответа от сервера
        recv_len = recv(client_socket, buffer, BUFFER_SIZE, 0);
        if (recv_len <= 0) {
            printf("Соединение с сервером разорвано\n");
            break;
        }

        // Вывод сообщения от сервера
        buffer[recv_len] = '\0';
        printf("Ответ от сервера: %s\n", buffer);
    }

    // Закрытие сокета
    close(client_socket);

    return 0;
}

