#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <sys/types.h>


void signal_handler(int signum) {
        printf("Process is Terminated (SIGTERM)\n");
        exit(SIGTERM);
}

int main() {

    signal(SIGTERM, signal_handler);

    pid_t pid = getpid();

    kill(pid,SIGTERM);
}
