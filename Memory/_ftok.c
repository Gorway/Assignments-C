#include <sys/types.h>
#include <sys/ipc.h>
#include <stdio.h>

int main() {
    const char *pathname = ".";
    int proj_id = 42;

    key_t key = ftok(pathname, proj_id);
    if (key == -1) {
        perror("ftok");
        return 1;
    }

    printf("Сгенерированный ключ IPC: %d\n", (int)key);

    return 0;
}

