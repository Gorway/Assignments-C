#include <stdio.h>
#include <unistd.h>

int main() {
    char *args[] = {"ls", "-l", NULL};

    // Выполнение команды ls с аргументом -l
    execvp(args[0], args);

    // Если execvp() завершилась с ошибкой, то мы оказались здесь
    perror("Ошибка при выполнении команды");
    return 1;
}

