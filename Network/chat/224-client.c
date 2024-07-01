#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>

#define SERVER_IP "127.0.0.1"
#define PORT 12345
#define BUFFER_SIZE 1024

int main() {
    int client_socket;
    struct sockaddr_in server_address;
    char buffer[BUFFER_SIZE];
    int total_received = 0;

    // Создание сокета
    client_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (client_socket == -1) {
        perror("Ошибка при создании сокета");
        exit(EXIT_FAILURE);
    }

    // Настройка адреса сервера
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = inet_addr(SERVER_IP);
    server_address.sin_port = htons(PORT);

    // Подключение к серверу
    if (connect(client_socket, (struct sockaddr *)&server_address, sizeof(server_address)) < 0) {
        perror("Ошибка при подключении к серверу");
        exit(EXIT_FAILURE);
    }

    printf("Подключение к серверу успешно.\n");

    // Прием сообщений от сервера
    while (1) {
        ssize_t bytes_received = recv(client_socket, buffer + total_received, BUFFER_SIZE - total_received, 0);
        if (bytes_received < 0) {
            perror("Ошибка при приеме сообщения от сервера");
            exit(EXIT_FAILURE);
        } else if (bytes_received == 0) {
            printf("Соединение с сервером разорвано.\n");
            break;
        } else {
            // Увеличиваем счетчик общего количества принятых байт
            total_received += bytes_received;
        }
    }

    // Отправка принятых сообщений обратно на сервер с опцией MSG_MORE
    if (send(client_socket, buffer, total_received, MSG_MORE) < 0) {
        perror("Ошибка при отправке сообщения на сервер");
        exit(EXIT_FAILURE);
    }

    // Закрытие клиентского сокета
    close(client_socket);

    return 0;
}

