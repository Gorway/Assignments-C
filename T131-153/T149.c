#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>


int globalVariable = 0;

int main() {

    pid_t child_pid = fork();

    if (child_pid == 0) {

        printf("Child process start working.\n");


        for (int i = 0; i < 5; ++i) {
            globalVariable++;
            sleep(1); 
        }
        printf("Result: %d\n", globalVariable);
        printf("Child process end.\n");
        exit(0);
    } else if (child_pid > 0) {

        printf("Parent process is waiting...\n");


        waitpid(child_pid, NULL, 0);

        printf("Parent process end.\n");
    } else {
        perror("Error during child process creating");
        exit(1);
    }

    return 0;
}

