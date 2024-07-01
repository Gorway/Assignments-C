#include <stdio.h>
#include <stdlib.h>

// Рекурсивная функция для печати массива в обратном порядке
void printReverse(int *arr, int size) {
    // Базовый случай: если размер массива равен 0, завершаем рекурсию
    if (size == 0) {
        return;
    }

    // Выделение динамической памяти для нового массива на 1 элемент меньше
    int *newArr = (int *)malloc((size - 1) * sizeof(int));

    if (newArr == NULL) {
        printf("Ошибка выделения памяти.\n");
        exit(1); // Выход из программы в случае ошибки
    }

    // Копирование элементов в новый массив
    for (int i = 0; i < size - 1; i++) {
        newArr[i] = arr[i];
    }

    // Печать последнего элемента
    printf("%d ", arr[size - 1]);

    // Рекурсивный вызов для нового массива
    printReverse(newArr, size - 1);

    // Освобождение выделенной памяти для нового массива
    free(newArr);
}

int main() {
    int n;

    // Ввод размера массива
    printf("Введите размер массива: ");
    scanf("%d", &n);

    // Выделение динамической памяти под массив
    int *arr = (int *)malloc(n * sizeof(int));

    if (arr == NULL) {
        printf("Ошибка выделения памяти.\n");
        return 1;
    }

    // Ввод элементов массива
    printf("Введите %d элементов массива:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Вызываем рекурсивную функцию для печати в обратном порядке
    printf("Массив в обратном порядке:\n");
    printReverse(arr, n);

    // Освобождение выделенной памяти
    free(arr);

    return 0;
}

