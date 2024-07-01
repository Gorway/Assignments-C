#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h>

int main() {
    pid_t pid = fork();

    if (pid == 0) {
        // Код потомка
        printf("Child process\n");
        // Выполнение задачи потомка
        _exit(42); // Завершение потомка с exit status 42
    } else if (pid > 0) {
        // Код родительского процесса
        printf("Parent process\n");
        int status;
        waitpid(pid, &status, 0);
        if (WIFEXITED(status)) {
            printf("Child exited with status: %d\n", WEXITSTATUS(status));
        }
    } else {
        perror("fork");
        return 1;
    }

    return 0;
}

