#include <stdio.h>
#include <pthread.h>

#define NUM_THREADS 5
#define MAX_COUNT 1000

int counter = 0; 
pthread_mutex_t mutex;

void *increment_counter(void *thread_id) {
    long tid = (long)thread_id;
    
    for (int i = 0; i < MAX_COUNT; i++) {
        
        pthread_mutex_lock(&mutex);
        counter++;
        printf("Thread %ld incremented counter to %d\n", tid, counter);
        pthread_mutex_unlock(&mutex);
    }
    
    pthread_exit(NULL);
}

int main() {
    pthread_t threads[NUM_THREADS];
    pthread_mutex_init(&mutex, NULL);
    
    for (long i = 0; i < NUM_THREADS; i++) {
        pthread_create(&threads[i], NULL, increment_counter, (void *)i);
    }
    
    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }
    
    pthread_mutex_destroy(&mutex); 
    
    printf("Final counter value: %d\n", counter);
    
    return 0;
}

