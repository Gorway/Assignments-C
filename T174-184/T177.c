#include <stdio.h>
#include <signal.h>
#include <stdlib.h>

void signal_handler(int signum) {
    printf("Program is stoped with signal: %d (SIGINT)\n", signum);
    exit(signum);
}


int main() {

        signal(SIGINT, signal_handler);

        printf("Program running. Press Cntrl+C to stop.\n");

        while(1) {

        }

        return 0;
}
