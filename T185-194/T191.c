
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>

#define MAX 100000

 void* increase(void *arg);
 void* decrease(void *arg);

 int global_variable = 0;

 sem_t mutex;

 int main(int argc, char **argv) {

    sem_init(&mutex, 0 , 1);

    pthread_t tid1, tid2;
    
    pthread_create(&tid1, NULL, increase, NULL);
    pthread_create(&tid2, NULL, decrease, NULL);
    pthread_join(tid1, NULL);
    pthread_join(tid2, NULL);

    printf("Global variable value: %d\n", global_variable);

    return 0;

 }

void *increase(void *vargp) {
    for(int i = 0; i < MAX; ++i) {
    sem_wait(&mutex);    
   global_variable++;
    sem_post(&mutex);
   
   }
    pthread_exit(NULL);
}


void *decrease(void *vargp) {
    for(int i = 0; i < MAX; ++i) {
    sem_wait(&mutex);    
    global_variable--;
    sem_post(&mutex);
   
   }
    pthread_exit(NULL);
}
