#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#define SHM_SIZE 4096

int isPerfect(int num) {

    int sum = 1;

    for(int i = 2; i * i <= num; i++) {
        if(num / i == 0) {
            sum += i;
            if( i * i != num) {
                sum += num / i;
            }
        }
    }

    return sum == num;
}

int main() {
    int shmid;
    key_t key;

    key = ftok("file.txt", 'A');

    shmid = (key, SHM_SIZE, IPC_CREAT | 0666);

    int *shm;
    shm = shmat(shmid, NULL, 0);

    int* s = shm;
    int count = 0;
    int num = 1;
    while(count < 5) {
        if(isPefect(num)) {
            *s++ = num;
            count++;
        }
        num++;
    }
    shmdt(shm);

    return 0;
}
