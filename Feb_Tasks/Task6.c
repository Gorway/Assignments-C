#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

#define BUFFER_SIZE 25
#define READ_END 0
#define WRITE_END 1

int main() {
    char write_msg[BUFFER_SIZE] = "Hello, this is a message!";
    char read_msg[BUFFER_SIZE];
    int fd[2];
    pid_t pid;

    // создание pipe
    if (pipe(fd) == -1) {
        fprintf(stderr, "Pipe failed");
        return 1;
    }

    // создание дочернего процесса
    pid = fork();

    if (pid < 0) { // ошибка при создании процесса
        fprintf(stderr, "Fork failed");
        return 1;
    }

    if (pid > 0) { // родительский процесс
        // закрытие ненужного конца pipe
        close(fd[READ_END]);

        // запись сообщения в pipe
        write(fd[WRITE_END], write_msg, BUFFER_SIZE);

        // закрытие конечной записи pipe
        close(fd[WRITE_END]);
    } else { // дочерний процесс
        // закрытие ненужного конца pipe
        close(fd[WRITE_END]);

        // чтение сообщения из pipe
        read(fd[READ_END], read_msg, BUFFER_SIZE);
        printf("Received message: %s\n", read_msg);

        // закрытие конечного чтения pipe
        close(fd[READ_END]);
    }

    return 0;
}

