#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

void run_empty_process() {
    pid_t pid = fork();

    if (pid == -1) {
        printf("Error.");
        exit(1);
    }

    if (pid == 0) {

        printf("Child process with PID %d is created.\n", getpid());
        exit(1);
    }
}

int main() {
    pid_t child_pids[3];


    for (int i = 0; i <= 3; ++i) {
        run_empty_process();
        child_pids[i] = getpid();
    


    int status;
    pid_t finished_pid = wait(&status);
    printf("Child process with PID %d has finished.\n", finished_pid);


    for (int i = 0; i < 3; ++i) {
        if (child_pids[i] != finished_pid) {
            printf("Killing child process with PID %d.\n", child_pids[i]);
            kill(child_pids[i], SIGTERM);
        }
    }

    return 0;
  }
}
