#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

void* calculate_sum(void* args);

int main() {

    pthread_t tid;

    pthread_create(&tid, NULL, calculate_sum, NULL);
    pthread_join(tid, NULL);
    exit(0);
}

void* calculate_sum(void* args) {

    int array[5] = { 1,2,3,4,5 };
    int result;
    for(int i = 0; i < 5; i++) {
        result += array[i];
    }
    printf("%d\n", result);
}
