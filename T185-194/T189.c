#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

void* thread(void* arg);

int main() {

    pid_t pid;

    if((pid = fork()) == 0) { 
        pthread_t tid;
        
        pthread_create(&tid, NULL, thread, getpid());
        pthread_join(tid, (void**)&pid);

        exit(0);
    } else {
        printf("Parent process ID: %d\n", getpid());
    }
}

void* thread(void* args) {
    int pid = (int)args;
    printf("Thread ID: %ld\n", pthread_self());
    printf("Process ID: %d\n", pid);
}


