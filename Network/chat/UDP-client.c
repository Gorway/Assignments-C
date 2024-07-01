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

    // Создание UDP сокета
    client_socket = socket(AF_INET, SOCK_DGRAM, 0);

    // Настройка структуры server_addr
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = inet_addr(SERVER_IP);
    server_addr.sin_port = htons(PORT);

    // Ввод числа от пользователя
    double number;
    printf("Введите число: ");
    scanf("%lf", &number);

    // Преобразование числа в строку
    snprintf(buffer, BUFFER_SIZE, "%.2f", number);

    // Отправка сообщения на сервер
    sendto(client_socket, buffer, strlen(buffer), 0, (struct sockaddr *)&server_addr, sizeof(server_addr));
    printf("Отправлено серверу: %s\n", buffer);

    // Получение ответа от сервера
    recv_len = recvfrom(client_socket, buffer, BUFFER_SIZE, 0, NULL, NULL);
    buffer[recv_len] = '\0'; // Добавляем нулевой символ в конец строки
    printf("Получено от сервера: %s\n", buffer);

    // Закрытие сокета
    close(client_socket);

    return 0;
}

