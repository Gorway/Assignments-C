#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NUM_THREADS 5

pthread_mutex_t mutex;

void *thread_function(void *arg) {
    int thread_id = *((int *) arg);
    pthread_mutex_lock(&mutex);
    printf("Thread %d started.\n", thread_id);
    // Критическая секция, где поток выполняет свою работу
    printf("Thread %d is working.\n", thread_id);
    pthread_mutex_unlock(&mutex);
    printf("Thread %d finished.\n", thread_id);
    pthread_exit(NULL);
}

int main() {
    pthread_t threads[NUM_THREADS];
    int thread_args[NUM_THREADS];
    int result_code;
    
    // Инициализация мьютекса
    if (pthread_mutex_init(&mutex, NULL) != 0) {
        printf("Mutex initialization failed.\n");
        return 1;
    }

    // Создание потоков
    for (int i = 0; i < NUM_THREADS; ++i) {
        thread_args[i] = i;
        result_code = pthread_create(&threads[i], NULL, thread_function, &thread_args[i]);
        if (result_code != 0) {
            printf("Thread creation failed: %d\n", result_code);
            return 1;
        }
    }

    // Ожидание завершения потоков
    for (int i = 0; i < NUM_THREADS; ++i) {
        result_code = pthread_join(threads[i], NULL);
        if (result_code != 0) {
            printf("Thread join failed: %d\n", result_code);
            return 1;
        }
    }

    // Уничтожение мьютекса
    pthread_mutex_destroy(&mutex);

    return 0;
}

