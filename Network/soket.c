#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <sys/wait.h>

#define PORT 8080
#define BUFFER_SIZE 1024

void reverseString(char* str) {
    int start = 0;
    int end = strlen(str) - 1;
    while (start < end) {
        char temp = str[start];
        str[start] = str[end];
        str[end] = temp;
        start++;
        end--;
    }
}

int main() {
    int sockfd, newsockfd, pid;
    struct sockaddr_in serv_addr, cli_addr;
    int clilen = sizeof(cli_addr);
    char buffer[BUFFER_SIZE];

    // Создание сокета
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    // Настройка адреса сервера
    memset(&serv_addr, '0', sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(PORT);

    // Привязка сокета к адресу и порту
    if (bind(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        perror("Bind failed");
        exit(EXIT_FAILURE);
    }

    // Прослушивание на сокете
    if (listen(sockfd, 5) < 0) {
        perror("Listen failed");
        exit(EXIT_FAILURE);
    }

    // Принятие подключения
    if ((newsockfd = accept(sockfd, (struct sockaddr *)&cli_addr, (socklen_t *)&clilen)) < 0) {
        perror("Accept failed");
        exit(EXIT_FAILURE);
    }

    // Создание нового процесса
    if ((pid = fork()) < 0) {
        perror("Fork failed");
        exit(EXIT_FAILURE);
    }

    // Потомок
    if (pid == 0) {
        close(sockfd); // Закрытие дескриптора сокета
        // Чтение из сокета
        read(newsockfd, buffer, BUFFER_SIZE);
        printf("Received message: %s\n", buffer);
        // Переворот строки
        reverseString(buffer);
        // Отправка перевернутой строки обратно в сокет
        write(newsockfd, buffer, strlen(buffer));
        exit(0);
    } else { // Родитель
        close(newsockfd); // Закрытие дескриптора нового сокета
        // Ожидание завершения дочернего процесса
        wait(NULL);
    }
    return 0;
}

