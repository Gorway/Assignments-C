#include <stdio.h>
#include <signal.h>
#include <setjmp.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <stdlib.h>


sigjmp_buf jmpbuf;

// Обработчик сигнала SIGSEGV
void sigsegv_handler(int signum) {
    printf("Получен сигнал SIGSEGV\n");
    siglongjmp(jmpbuf, 1); // Возвращаемся к точке jmpbuf
}

int main() {
    // Установка обработчика сигнала SIGSEGV
    signal(SIGSEGV, sigsegv_handler);

    // Продолжение выполнения программы
    if (sigsetjmp(jmpbuf, 1) == 0) {
        // Попытка доступа к памяти по недопустимому адресу
        int *ptr = NULL;
        *ptr = 10; // Это вызовет SIGSEGV
    }

    printf("Программа продолжает работу после SIGSEGV\n");

    // Продолжение выполнения программы и печать "Hello, world!"
    while(1) {
        printf("Hello, world!\n");
        sleep(1);
    }

    return 0;
}

