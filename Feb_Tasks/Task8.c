#include <stdio.h>
#include <unistd.h>
#include <string.h>

#define BUFFER_SIZE 1024

int main() {
    int parent_to_child_pipe[2];
    int child_to_parent_pipe[2];
    char parent_message[BUFFER_SIZE];
    char child_message[BUFFER_SIZE];
    pid_t pid;

    // Создание первого pipe (родитель -> дочерний процесс)
    if (pipe(parent_to_child_pipe) == -1) {
        perror("Pipe failed");
        return 1;
    }

    // Создание второго pipe (дочерний процесс -> родитель)
    if (pipe(child_to_parent_pipe) == -1) {
        perror("Pipe failed");
        return 1;
    }

    // Создание дочернего процесса
    pid = fork();

    if (pid < 0) {
        perror("Fork failed");
        return 1;
    }

    if (pid > 0) { // Родительский процесс
        // Закрываем ненужные концы pipe
        close(parent_to_child_pipe[0]);
        close(child_to_parent_pipe[1]);

        // Отправляем сообщение дочернему процессу
        printf("Родительский процесс отправляет сообщение: ");
        fgets(parent_message, BUFFER_SIZE, stdin);
        write(parent_to_child_pipe[1], parent_message, strlen(parent_message) + 1);

        // Получаем ответ от дочернего процесса
        read(child_to_parent_pipe[0], child_message, BUFFER_SIZE);
        printf("Родительский процесс получает ответ: %s", child_message);

        // Закрываем концы pipe
        close(parent_to_child_pipe[1]);
        close(child_to_parent_pipe[0]);
    } else { // Дочерний процесс
        // Закрываем ненужные концы pipe
        close(parent_to_child_pipe[1]);
        close(child_to_parent_pipe[0]);

        // Получаем сообщение от родительского процесса
        read(parent_to_child_pipe[0], child_message, BUFFER_SIZE);
        printf("Дочерний процесс получает сообщение: %s", child_message);

        // Изменяем сообщение (например, преобразуем в верхний регистр)
        for (int i = 0; child_message[i] != '\0'; i++) {
            if (child_message[i] >= 'a' && child_message[i] <= 'z') {
                child_message[i] = child_message[i] - 32;
            }
        }

        // Отправляем измененное сообщение родительскому процессу
        write(child_to_parent_pipe[1], child_message, strlen(child_message) + 1);

        // Закрываем концы pipe
        close(parent_to_child_pipe[0]);
        close(child_to_parent_pipe[1]);
    }

    return 0;
}

