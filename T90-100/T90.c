#include <stdio.h>
#include <stdlib.h>

// Функция для проверки, является ли число простым
int isPrime(int num) {
    if (num <= 1) {
        return 0;  // Число 1 и меньше не считается простым
    }
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) {
            return 0;  // Не является простым, если делится нацело
        }
    }
    return 1;  // Является простым числом
}

int main() {
    int size;

    // Ввод размера массива
    printf("Введите размер массива: ");
    scanf("%d", &size);

    if (size <= 0) {
        printf("Размер массива должен быть положительным.\n");
        return 1;
    }

    // Выделение динамической памяти под массив
    int* primeArray = (int*)malloc(size * sizeof(int));

    if (primeArray == NULL) {
        printf("Не удалось выделить память.\n");
        return 1;
    }

    // Заполнение массива простыми числами
    int currentSize = 0;
    int currentNumber = 2;

    while (currentSize < size) {
        if (isPrime(currentNumber)) {
            primeArray[currentSize] = currentNumber;
            currentSize++;
        }
        currentNumber++;
    }

    // Вывод массива простых чисел
    printf("Простые числа: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", primeArray[i]);
    }
    
    printf("\n");
    // Освобождение выделенной памяти
    free(primeArray);

    return 0;
}

