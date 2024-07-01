#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <sys/wait.h>

#define PORT 8080
#define BUFFER_SIZE 1024

void execute_command(int client_socket, char *command) {
    char buffer[BUFFER_SIZE] = {0};
    FILE *pipe_fp;

    // Выполнение команды и чтение вывода в поток
    if ((pipe_fp = popen(command, "r")) == NULL) {
        perror("popen failed");
        exit(EXIT_FAILURE);
    }

    // Чтение вывода команды и отправка его клиенту
    while (fgets(buffer, BUFFER_SIZE, pipe_fp) != NULL) {
        send(client_socket, buffer, strlen(buffer), 0);
    }

    // Закрытие потока и завершение работы
    pclose(pipe_fp);
    close(client_socket);
    exit(EXIT_SUCCESS);
}

int main() {
    int server_socket, new_socket;
    struct sockaddr_in address;
    int addrlen = sizeof(address);
    char buffer[BUFFER_SIZE] = {0};

    // Создание сокета
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

    printf("Server listening on port %d...\n", PORT);

    while (1) {
        // Принятие входящего соединения
        if ((new_socket = accept(server_socket, (struct sockaddr *)&address, (socklen_t *)&addrlen)) < 0) {
            perror("accept");
            exit(EXIT_FAILURE);
        }

        printf("Connection accepted\n");

        // Чтение команды от клиента
        read(new_socket, buffer, BUFFER_SIZE);
        printf("Command received from client: %s\n", buffer);

        // Создание дочернего процесса для выполнения команды
        pid_t pid = fork();
        if (pid < 0) {
            perror("fork failed");
            exit(EXIT_FAILURE);
        } else if (pid == 0) {
            // Дочерний процесс выполняет команду и отправляет результат клиенту
            execute_command(new_socket, buffer);
        } else {
            // Родительский процесс закрывает новый сокет и продолжает прослушивание
            close(new_socket);
        }
    }

    return 0;
}

