#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <errno.h>

#define MSG_SIGNAL "Сигнал обработан"

// Обработчик сигнала
void signal_handler(int signum) {
    fprintf(stderr, "Сигнал %d получен. %s\n", signum, MSG_SIGNAL);
    // Установка значения errno
    errno = signum;
}

int main() {
    // Установка обработчика для SIGINT
    if (signal(SIGINT, signal_handler) == SIG_ERR) {
        perror("Ошибка при установке обработчика для SIGINT");
        exit(EXIT_FAILURE);
    }

    // Установка обработчика для SIGTERM
    if (signal(SIGTERM, signal_handler) == SIG_ERR) {
        perror("Ошибка при установке обработчика для SIGTERM");
        exit(EXIT_FAILURE);
    }

    // Имитация обработки сигнала
    // В реальной программе здесь могут быть другие действия
    // Важно: при возникновении сигнала обработчик будет вызван асинхронно
    // к основной логике программы, поэтому в обработчике стоит избегать
    // длительных или блокирующих операций
    while (1) {
        // Важно: этот код не является частью обработчика сигнала,
        // а просто демонстрирует имитацию основной логики программы
        // с выводом сообщения и паузой
        printf("Основная логика программы...\n");
        sleep(1);
    }

    return 0;
}

