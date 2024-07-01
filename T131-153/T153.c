#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

void run_child_process(int *child_pids, int index) {
    pid_t pid = fork();


    if (pid == 0) {

        printf("Child process with PID %d is created.\n", getpid());
        exit(EXIT_SUCCESS);
    } else {

        child_pids[index] = pid;
    }
}

int main() {
    int child_pids[3];


    for (int i = 0; i < 3; ++i) {
        run_child_process(child_pids, i);
    }


    for (int i = 0; i < 3; ++i) {
        wait(NULL);
    }


    for (int i = 0; i < 2; ++i) {
        for (int j = i + 1; j < 3; ++j) {
            if (child_pids[i] > child_pids[j]) {

                int temp = child_pids[i];
                child_pids[i] = child_pids[j];
                child_pids[j] = temp;
            }
        }
    }

    printf("Sorted Child Process IDs: %d, %d, %d\n", child_pids[0], child_pids[1], child_pids[2]);

    return 0;
}

