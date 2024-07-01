#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 8888
#define BUFFER_SIZE 1024

int main() {
    int server_socket;
    struct sockaddr_in server_addr, client_addr;
    char buffer[BUFFER_SIZE];
    int recv_len;

    // Создание UDP сокета
    server_socket = socket(AF_INET, SOCK_DGRAM, 0);

    // Настройка структуры server_addr
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);

    // Привязка сокета к адресу и порту
    bind(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr));

    printf("Сервер запущен. Ожидание сообщений...\n");

    // Принятие сообщений от клиентов и обработка их
    while (1) {
        socklen_t client_addr_len = sizeof(client_addr);
        recv_len = recvfrom(server_socket, buffer, BUFFER_SIZE, 0, (struct sockaddr *)&client_addr, &client_addr_len);
        buffer[recv_len] = '\0'; // Добавляем нулевой символ в конец строки
        printf("Получено от клиента: %s\n", buffer);

        // Преобразование полученной строки в число
        double number = atof(buffer);

        // Вычисление квадрата числа
        double square = number * number;

        // Преобразование результата в строку
        snprintf(buffer, BUFFER_SIZE, "%.2f", square);

        // Отправка ответа клиенту
        sendto(server_socket, buffer, strlen(buffer), 0, (struct sockaddr *)&client_addr, client_addr_len);
        printf("Отправлено клиенту: %s\n", buffer);
    }

    // Закрытие серверного сокета (не достижимо в данном примере)
    close(server_socket);

    return 0;
}

