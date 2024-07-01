#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>

void createProcesses(int count) {
    for (int i = 0; i < count; ++i) {
        pid_t child_pid = fork();

        if (child_pid < 0) {
            fprintf(stderr, "Ошибка: Процесс не создан\n");
            exit(EXIT_FAILURE);
        } else if (child_pid == 0) {
            // Код, выполняемый дочерним процессом
            printf("Дочерний процесс: PID=%d\n", getpid());
            exit(EXIT_SUCCESS); // Дочерний процесс завершает свое выполнение
        } else {
            // Родительский процесс
            wait(NULL); // Ждем завершения дочернего процесса
        }
    }
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Использование: %s <количество процессов>\n", argv[0]);
        return EXIT_FAILURE;
    }

    int count = atoi(argv[1]);

    if (count <= 0) {
        fprintf(stderr, "Ошибка: Введите положительное число процессов\n");
        return EXIT_FAILURE;
    }

    createProcesses(count);

    return EXIT_SUCCESS;
}

