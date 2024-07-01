#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <signal.h>

#define ROWS 5
#define COLS 5

int **matrix;

void segfault_handler(int sig);

void *create_matrix(void *arg);

void free_matrix();

void segfault_handler(int sig) {
    printf("Segmentation fault occurred in the child process.\n");
    pthread_t thread;
    pthread_create(&thread, NULL, create_matrix, NULL);
    pthread_join(thread, NULL);
    exit(EXIT_SUCCESS); // Завершаем дочерний процесс
}

void *create_matrix(void *arg) {
    matrix = (int **)malloc(ROWS * sizeof(int *));
    for (int i = 0; i < ROWS; ++i) {
        matrix[i] = (int *)malloc(COLS * sizeof(int));
    }

    printf("Matrix created successfully.\n");
    pthread_exit(NULL);
}

void free_matrix() {
    for (int i = 0; i < ROWS; ++i) {
        free(matrix[i]);
    }
    free(matrix);
    printf("Matrix freed successfully.\n");
}

int main() {
    pid_t pid = fork();

    if (pid == -1) {
        printf("Failed to create child process.\n");
        return 1;
    }

    if (pid == 0) { // Child process
        signal(SIGSEGV, segfault_handler);
        int *ptr = NULL;
        *ptr = 10; // Cause segmentation fault
        // Нет необходимости вызывать exit() здесь, так как segfault_handler завершит процесс
    } else { // Parent process
        pthread_t thread;
        pthread_create(&thread, NULL, (void *(*)(void *))free_matrix, NULL);
        pthread_join(thread, NULL);
    }

    return 0;
}

