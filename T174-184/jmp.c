#include <stdio.h>
#include <setjmp.h>

jmp_buf jmpbuf;

void function2() {
    printf("В функции 2\n");
    longjmp(jmpbuf, 1); // Прыжок обратно к месту, сохраненному в jmpbuf
}

void function1() {
    printf("В функции 1\n");
    function2();
    printf("Эта строка не будет напечатана\n");
}

int main() {
    if (setjmp(jmpbuf) == 0) {
        printf("Осуществление прыжка внутрь function1\n");
        function1();
    } else {
        printf("Осуществление прыжка назад из function2\n");
    }

    printf("Программа завершена\n");

    return 0;
}

