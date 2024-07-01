#include <stdio.h>
#include <signal.h>
#include <unistd.h>

int main() {
    // Печать "Hello"
    printf("Hello\n");

    // Получение идентификатора текущего процесса
    pid_t pid = getpid();

    // Отправка сигнала SIGTERM текущему процессу
    if (kill(pid, SIGTERM) == 0) {
        printf("Программа завершена с использованием kill.\n");
    } else {
        perror("Ошибка при использовании kill");
    }

    // Код ниже после отправки сигнала не будет выполнен
    printf("Этот текст не будет выведен\n");

    return 0;
}

