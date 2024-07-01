#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

#define ROWS 3
#define COLS 3

int **matrix;

void *allocate_and_initialize_matrix(void *arg) {
    matrix = (int **)malloc(ROWS * sizeof(int *));
    if (matrix == NULL) {
        perror("Failed to allocate memory for matrix");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < ROWS; ++i) {
        matrix[i] = (int *)malloc(COLS * sizeof(int));
        if (matrix[i] == NULL) {
            perror("Failed to allocate memory for matrix row");
            exit(EXIT_FAILURE);
        }
        for (int j = 0; j < COLS; ++j) {
            matrix[i][j] = i * COLS + j;  // Initialize matrix with some values
        }
    }
    printf("Matrix allocated and initialized successfully.\n");
    pthread_exit(NULL);
}

int main() {
    pid_t pid = fork();

    if (pid == -1) {
        perror("Fork failed");
        exit(EXIT_FAILURE);
    } else if (pid == 0) {  // Child process
        printf("Child process is waiting for input...\n");
        getchar();  // Ждем ввода с клавиатуры (например, нажатия Enter)
        
        // После получения ввода запускаем поток для выделения и инициализации матрицы
        pthread_t thread;
        int result_code = pthread_create(&thread, NULL, allocate_and_initialize_matrix, NULL);
        if (result_code != 0) {
            perror("Thread creation failed");
            exit(EXIT_FAILURE);
        }

        pthread_join(thread, NULL);
    } else {  // Parent process
        // Ожидаем завершение дочернего процесса
        int child_status;
        waitpid(pid, &child_status, 0);
        if (WIFEXITED(child_status)) {
            printf("Child process exited successfully.\n");
        } else {
            fprintf(stderr, "Child process exited abnormally.\n");
        }
    }

    return 0;
}

