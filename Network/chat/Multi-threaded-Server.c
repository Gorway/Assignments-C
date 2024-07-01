#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define PORT 8888
#define BUFFER_SIZE 1024

void *client_handler(void *arg) {
    int client_socket = *((int *)arg);
    char buffer[BUFFER_SIZE];
    int read_size;

    // Принимаем данные от клиента
    while ((read_size = recv(client_socket, buffer, BUFFER_SIZE, 0)) > 0) {
        // Обработка данных (в данном примере просто выводим их на экран)
        buffer[read_size] = '\0'; // Добавляем нулевой символ в конец строки
        printf("Получено от клиента: %s\n", buffer);
        
        // Отправляем данные обратно клиенту
        send(client_socket, buffer, strlen(buffer), 0);
    }

    // Закрываем сокет клиента и завершаем поток
    close(client_socket);
    pthread_exit(NULL);
}

int main() {
    int server_socket, client_socket;
    struct sockaddr_in server_addr, client_addr;
    socklen_t client_addr_len;
    pthread_t thread_id;

    // Создание TCP сокета
    server_socket = socket(AF_INET, SOCK_STREAM, 0);

    // Настройка структуры server_addr
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);

    // Привязка сокета к адресу и порту
    bind(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr));

    // Прослушивание входящих соединений
    listen(server_socket, 5);
    printf("Сервер запущен. Ожидание клиентов...\n");

    // Принятие клиентов и создание потока для каждого клиента
    while (1) {
        client_addr_len = sizeof(client_addr);
        client_socket = accept(server_socket, (struct sockaddr *)&client_addr, &client_addr_len);
        printf("Подключен новый клиент\n");

        // Создание потока для обработки запроса клиента
        pthread_create(&thread_id, NULL, client_handler, (void *)&client_socket);
    }

    // Закрытие серверного сокета (не достижимо в данном примере)
    close(server_socket);

    return 0;
}

