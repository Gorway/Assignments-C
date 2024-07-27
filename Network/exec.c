#include <stdio.h>
#include <unistd.h>

int main() {
    char *args[] = {"ls", "-l", NULL};

    execvp(args[0], args);

    perror("Ошибка при выполнении команды");
    return 1;
}

