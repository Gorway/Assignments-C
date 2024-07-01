#include <stdio.h>
#include <unistd.h>

int main() {
    pid_t child_pid;

    child_pid = fork();

    if (child_pid < 0) {
        fprintf(stderr, "Error.\n");
        return 1;
    } else if (child_pid == 0) {
        // Код, выполняемый дочерним процессом
        printf("Child Proccess: PID=%d\n", getpid());
    } else {
        // Код, выполняемый родительским процессом
        printf("Parent Process: PID=%d\n", getpid());
    }

    return 0;
}

