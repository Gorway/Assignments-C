#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define PORT 12345
#define BUFFER_SIZE 1024

int main() {
    int server_socket, client_socket;
    struct sockaddr_in server_address, client_address;
    socklen_t client_address_length = sizeof(client_address);

    // Создание серверного сокета
    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket == -1) {
        perror("Error creating server socket");
        exit(EXIT_FAILURE);
    }

    // Настройка адреса сервера
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = INADDR_ANY;
    server_address.sin_port = htons(PORT);

    // Привязка сокета к адресу и порту
    if (bind(server_socket, (struct sockaddr *)&server_address, sizeof(server_address)) < 0) {
        perror("Error binding server socket");
        exit(EXIT_FAILURE);
    }

    // Ожидание входящих подключений
    if (listen(server_socket, 10) < 0) {
        perror("Error listening for connections");
        exit(EXIT_FAILURE);
    }

    printf("Server is running. Waiting for connections...\n");

    // Принятие входящего подключения
    client_socket = accept(server_socket, (struct sockaddr *)&client_address, &client_address_length);
    if (client_socket < 0) {
        perror("Error accepting connection");
        exit(EXIT_FAILURE);
    }

    printf("Client connected\n");

    // Буфер для хранения сообщений
    char buffer[BUFFER_SIZE];
    size_t buffer_length = 0;

    // Прием и обработка сообщений от клиента
    while (1) {
        ssize_t bytes_received = recv(client_socket, buffer + buffer_length, BUFFER_SIZE - buffer_length, 0);
        if (bytes_received < 0) {
            perror("Error receiving message from client");
            exit(EXIT_FAILURE);
        } else if (bytes_received == 0) {
            printf("Client disconnected\n");
            break;
        }

        buffer_length += bytes_received;

        // Проверка, если сообщение "END\n", завершить чтение данных из буфера
        if (strstr(buffer, "END\n") != NULL) {
            printf("Received end token. Stop receiving messages from client\n");
            break;
        }
    }

    // Отправка всех сообщений обратно клиенту
    ssize_t bytes_sent = send(client_socket, buffer, buffer_length, 0);
    if (bytes_sent < 0) {
        perror("Error sending message to client");
        exit(EXIT_FAILURE);
    }

    // Закрытие сокета клиента
    close(client_socket);

    // Закрытие серверного сокета
    close(server_socket);

    return 0;
}

