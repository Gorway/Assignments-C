#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>

#define PORT 12345
#define BUFFER_SIZE 1024

int main() {
    int server_socket;
    struct sockaddr_in server_address, client_address;
    socklen_t client_address_length = sizeof(client_address);
    char buffer[BUFFER_SIZE];

    // Создание сокета
    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket == -1) {
        perror("Ошибка при создании сокета");
        exit(EXIT_FAILURE);
    }

    // Настройка адреса сервера
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = INADDR_ANY;
    server_address.sin_port = htons(PORT);

    // Привязка сокета к адресу и порту
    if (bind(server_socket, (struct sockaddr *)&server_address, sizeof(server_address)) < 0) {
        perror("Ошибка при привязке сокета");
        exit(EXIT_FAILURE);
    }

    // Прослушивание входящих соединений
    if (listen(server_socket, 5) < 0) {
        perror("Ошибка при прослушивании входящих соединений");
        exit(EXIT_FAILURE);
    }

    printf("Сервер запущен. Ожидание подключений...\n");

    // Принятие соединений и обработка запросов
    while (1) {
        int client_socket;
        
        // Принятие соединения от клиента
        client_socket = accept(server_socket, (struct sockaddr *)&client_address, &client_address_length);
        if (client_socket < 0) {
            perror("Ошибка при принятии соединения");
            exit(EXIT_FAILURE);
        }

        printf("Подключился клиент: %s:%d\n", inet_ntoa(client_address.sin_addr), ntohs(client_address.sin_port));

        // Сообщения клиента
        char *messages[] = {
            "Привет, клиент!\n",
            "Это сообщение будет отправлено вместе с последующими.\n",
            "Это последнее сообщение.\n"
        };

        // Отправка сообщений клиенту
        for (int i = 0; i < sizeof(messages) / sizeof(messages[0]); i++) {
            int flags = 0;
            if (i < sizeof(messages) / sizeof(messages[0]) - 1) {
                // Устанавливаем опцию MSG_MORE, чтобы сообщить ядру, что есть еще данные
                flags |= MSG_MORE;
            }
            if (send(client_socket, messages[i], strlen(messages[i]), flags) < 0) {
                perror("Ошибка при отправке сообщения клиенту");
                exit(EXIT_FAILURE);
            }
        }

        // Закрытие соединения с клиентом
        close(client_socket);
        printf("Соединение с клиентом закрыто.\n");
    }

    // Закрытие серверного сокета
    close(server_socket);

    return 0;
}

