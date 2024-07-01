#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

// Обработчик сигнала SIGPIPE
void sigpipe_handler(int signum) {
    printf("Произошел сигнал SIGPIPE\n");
}

int main() {
    // Установка обработчика для SIGPIPE
    if (signal(SIGPIPE, sigpipe_handler) == SIG_ERR) {
        perror("Ошибка при установке обработчика для SIGPIPE");
        exit(EXIT_FAILURE);
    }

    int pipefds[2];
    if (pipe(pipefds) == -1) {
        perror("Ошибка при создании канала");
        exit(EXIT_FAILURE);
    }

    // Закрываем конец для записи
    close(pipefds[1]);

    // Пытаемся записать в закрытый конец
    char buf[10];
    ssize_t bytes_written = write(pipefds[1], buf, sizeof(buf));
    
    printf("asdasd");
    return 0;
}

