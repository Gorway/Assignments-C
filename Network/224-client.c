#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT 12345
#define BUFFER_SIZE 1024

int main() {
    int client_socket;
    struct sockaddr_in server_address;

    // Создание сокета клиента
    client_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (client_socket == -1) {
        perror("Error creating client socket");
        exit(EXIT_FAILURE);
    }

    // Настройка адреса сервера
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = inet_addr("127.0.0.1"); // IP адрес сервера
    server_address.sin_port = htons(PORT);

    // Подключение к серверу
    if (connect(client_socket, (struct sockaddr *)&server_address, sizeof(server_address)) < 0) {
        perror("Error connecting to server");
        exit(EXIT_FAILURE);
    }

    printf("Connected to server\n");

    // Буфер для хранения сообщений
    char buffer[BUFFER_SIZE];

    // Считывание сообщений от пользователя и отправка на сервер
    printf("Enter messages to send to server (type 'exit' to quit):\n");
    while (1) {
        fgets(buffer, sizeof(buffer), stdin);
        if (strcmp(buffer, "exit\n") == 0) {
            // Если пользователь ввел 'exit', отправляем сообщение и выходим из цикла
            send(client_socket, buffer, strlen(buffer), MSG_EOR);
            break;
        }

        // Отправка сообщения на сервер с флагом MSG_EOR
        ssize_t bytes_sent = send(client_socket, buffer, strlen(buffer), MSG_EOR);
        if (bytes_sent < 0) {
            perror("Error sending message to server");
            exit(EXIT_FAILURE);
        }
    }

    // Закрытие сокета клиента
    close(client_socket);

    return 0;
}

