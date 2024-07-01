#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <sys/wait.h>


void signal_handler(int signum) {
      printf("Segmentation Fault (SIGSEGV), ignoring...\n");
}

int main() {

    pid_t child = fork();

    if(child < 0) {
        perror("fork");
        exit(EXIT_FAILURE);
    } else if(child == 0) {

        printf("Child process start working.\n");
        fflush(stdout);

        int* ptr = NULL;
        *ptr = 10;
        
        printf("Child process exits.\n");
        fflush(stdout);
    } else {

       printf("The Parent process is waiting for the child process to terminate.\n");

       signal(SIGSEGV, signal_handler);

       int status;
       
       waitpid(child, &status, 0);

        printf("Child process end working\n");

        printf("%d + %d = %d \n", 2,2,4);
        }
}
