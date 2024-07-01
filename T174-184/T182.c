#include <stdio.h>
#include <setjmp.h>

jmp_buf env;

void function1() {
    printf("Вызвана функция 1\n");
    longjmp(env, 1);  // Переход к точке возврата
}

void function2() {
    printf("Вызвана функция 2\n");
}

int main() {
    if (setjmp(env) == 0) {
        function1();  // Вызываем функцию 1
    } else {
        function2();  // Вызываем функцию 2
    }

    return 0;
}

