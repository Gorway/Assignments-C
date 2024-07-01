#include <stdio.h>
#include <stdlib.h>

// Прототип функции
void fillFibonacci(int* arr, int N);

int main() {
    int N;

    // Ввод значения N
    printf("Введите число N: ");
    scanf("%d", &N);

    if (N <= 0) {
        printf("N должно быть положительным числом.\n");
        return 1;
    }

    // Выделение памяти для массива
    int* fibonacciArray = (int*)malloc(N * sizeof(int));

    if (fibonacciArray == NULL) {
        printf("Не удалось выделить память.\n");
        return 1;
    }

    // Заполнение массива Фибоначчи
    fillFibonacci(fibonacciArray, N);

    // Вывод массива
    printf("Первые %d чисел Фибоначчи: ", N);
    for (int i = 0; i < N; i++) {
        printf("%d ", fibonacciArray[i]);
    }

    // Освобождение памяти
    free(fibonacciArray);

    return 0;
}

// Определение функции
void fillFibonacci(int* arr, int N) {
    if (N >= 1) {
        arr[0] = 0;
    }
    if (N >= 2) {
        arr[1] = 1;
    }

    for (int i = 2; i < N; i++) {
        arr[i] = arr[i - 1] + arr[i - 2];
    }
}

