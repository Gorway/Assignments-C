#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <pthread.h>

#define PORT 8888
#define MAX_CLIENTS 10
#define BUFFER_SIZE 1024

// Структура для хранения информации о клиенте
typedef struct {
    int socket;
    struct sockaddr_in addr;
} Client;

// Глобальный массив для хранения информации о клиентах
Client clients[MAX_CLIENTS];
int clients_count = 0;

// Функция для обработки сообщений от клиента
void *handle_client(void *arg) {
    int client_index = *((int *)arg);
    char buffer[BUFFER_SIZE];
    int recv_len;

    while ((recv_len = recv(clients[client_index].socket, buffer, BUFFER_SIZE, 0)) > 0) {
        buffer[recv_len] = '\0'; // Добавляем нулевой символ в конец строки

        // Отправляем сообщение всем остальным клиентам, кроме отправителя
        for (int i = 0; i < clients_count; i++) {
            if (i != client_index) {
                send(clients[i].socket, buffer, strlen(buffer), 0);
            }
        }
    }

    // Клиент отключился, закрываем сокет и освобождаем место в массиве клиентов
    close(clients[client_index].socket);
    printf("Клиент отключился\n");
    for (int i = client_index; i < clients_count - 1; i++) {
        clients[i] = clients[i + 1];
    }
    clients_count--;

    // Освобождение ресурсов и завершение потока
    pthread_exit(NULL);
}

int main() {
    int server_socket;
    struct sockaddr_in server_addr;
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
    printf("Сервер запущен. Ожидание подключений...\n");
    
    // Принятие клиентов и создание потока для каждого клиента
    while (1) {
        if (clients_count < MAX_CLIENTS) {
            // Принятие нового клиента
            socklen_t client_addr_len = sizeof(clients[clients_count].addr);
            clients[clients_count].socket = accept(server_socket, (struct sockaddr *)&clients[clients_count].addr, &client_addr_len);
            printf("Новый клиент подключился\n");
            
            // Создание потока для обработки клиента
            int *client_index = malloc(sizeof(int));
            *client_index = clients_count;
            pthread_create(&thread_id, NULL, handle_client, (void *)client_index);
            
            // Добавление клиента в массив
            clients_count++;
        }
    }
    
    // Закрытие серверного сокета (не достижимо в данном примере)
    close(server_socket);
    
    return 0;
}

