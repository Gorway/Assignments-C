#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

#define MAX_SIZE 100

// Функция, которую вызывает поток для вычисления суммы элементов массива
void* calculate_sum(void* arg) {
    int* array = (int*)arg;
    int size = array[0];
    int sum = 0;

    if (size == 0) {
        printf("Array size is 0. Returning to the child process.\n");
        pthread_exit(NULL);
    }

    for (int i = 1; i <= size; ++i) {
        sum += array[i];
    }

    int* result = (int*)malloc(sizeof(int));
    if (result == NULL) {
        perror("Memory allocation failed");
        pthread_exit(NULL);
    }

    *result = sum;
    pthread_exit(result);
}

int main() {
    int size;
    printf("Enter the size of the array: ");
    scanf("%d", &size);

    if (size < 0 || size > MAX_SIZE) {
        printf("Invalid array size.\n");
        return EXIT_FAILURE;
    }

    int* array = (int*)malloc((size + 1) * sizeof(int));
    if (array == NULL) {
        perror("Memory allocation failed");
        return EXIT_FAILURE;
    }

    array[0] = size; // Первый элемент - размер массива

    if (size > 0) {
        printf("Enter the elements of the array:\n");
        for (int i = 1; i <= size; ++i) {
            scanf("%d", &array[i]);
        }
    }

    pid_t pid = fork();

    if (pid < 0) {
        perror("fork");
        free(array);
        return EXIT_FAILURE;
    } else if (pid == 0) {
        // Мы в дочернем процессе
        pthread_t thread;

        if (pthread_create(&thread, NULL, calculate_sum, array) != 0) {
            perror("pthread_create failed");
            free(array);
            return EXIT_FAILURE;
        }

        int* result;
        if (pthread_join(thread, (void**)&result) != 0) {
            perror("pthread_join failed");
            free(array);
            return EXIT_FAILURE;
        }

        if (result == NULL) {
            printf("Child thread returned to the child process.\n");
        } else {
            printf("Sum of the array elements in the child process: %d\n", *result);
            free(result);
        }
    } else {
        // Мы в родительском процессе
        printf("Parent Process ID: %d\n", getpid());
    }

    free(array);

    return EXIT_SUCCESS;
}

