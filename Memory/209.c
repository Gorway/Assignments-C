#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <unistd.h>
#include <sys/wait.h>


#define SHM_SIZE 1024

int isSumEven(int num) {
    int sum = 0;
    while(num != 0) {
        sum += num % 10;

        num /= 10;
    }
    return sum % 2 == 0;
}

int main() {

    pid_t pid;

    int shmid;

    key_t key = ftok(".", 'E');

    shmid = shmget(key, SHM_SIZE, IPC_CREAT | 0666); 

    if((pid = fork()) == 0) {
        int* shm = shmat(shmid, NULL, 0);

        int number;
        printf("Child Process | Enter Number: ");
        scanf("%d", &number);

        if(isSumEven(number)) {
          *shm = number; 
        }
        shmdt(shm);

        exit(0);
        } else {
            wait(NULL);

        int* shm = shmat(shmid, NULL, 0);

        printf("Parent process | SHM content: %d\n", *shm);

        shmdt(shm);

        shmctl(shmid, IPC_RMID, NULL);
        }
}
