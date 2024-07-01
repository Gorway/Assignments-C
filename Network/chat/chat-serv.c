#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <pthread.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define PORT 8080
#define BUFFER_SIZE 1024

// Функция для обработки клиентских соединений
void *connection_handler(void *socket_desc) {
    int client_socket = *(int *)socket_desc;
    char buffer[BUFFER_SIZE];

    while (1) {
        int valread = read(client_socket, buffer, BUFFER_SIZE);
        if (valread == 0) {
            printf("Client disconnected\n");
            break;
        }
        printf("Client: %s", buffer);
        printf("Enter message for client: ");
        fgets(buffer, BUFFER_SIZE, stdin);
        send(client_socket, buffer, strlen(buffer), 0);
    }

    // Освобождаем дескриптор сокета
    close(client_socket);
    free(socket_desc);

    return NULL;
}

int main() {
    int server_socket, new_socket;
    struct sockaddr_in address;
    int addrlen = sizeof(address);

    // Создание серверного сокета
    if ((server_socket = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    // Привязка сокета к адресу и порту
    if (bind(server_socket, (struct sockaddr *)&address, sizeof(address)) < 0) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    // Прослушивание входящих соединений
    if (listen(server_socket, 3) < 0) {
        perror("listen");
        exit(EXIT_FAILURE);
    }

    puts("Waiting for connections...");

    while (1) {
        // Принятие входящего соединения
        if ((new_socket = accept(server_socket, (struct sockaddr *)&address, (socklen_t *)&addrlen)) < 0) {
            perror("accept");
            exit(EXIT_FAILURE);
        }

        printf("Connection accepted\n");

        // Создание нового потока для обработки соединения
        pthread_t thread;
        int *new_sock = malloc(sizeof(int));
        *new_sock = new_socket;

        if (pthread_create(&thread, NULL, connection_handler, (void *)new_sock) < 0) {
            perror("could not create thread");
            return 1;
        }
    }

    return 0;
}

