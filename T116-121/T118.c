#include <stdio.h>
#include <stdlib.h>

int isOddOrEven(int number) {
    return (number % 2 == 0) ? 1 : 0;
}

void rearrangeArray(int* arr, int size) {
    int* result = (int*)malloc(size * sizeof(int));
    if (result == NULL) {
        printf("Ошибка выделения памяти.\n");
        return;
    }

    int evenIndex = 0;
    int oddIndex = size - 1;

    for (int i = 0; i < size; i++) {
        if (isOddOrEven(arr[i])) {
            result[evenIndex++] = arr[i];
        } else {
            result[oddIndex--] = arr[i];
        }
    }

    for (int i = 0; i < size; i++) {
        arr[i] = result[i];
    }

    free(result);
}

int main() {
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int size = sizeof(arr) / sizeof(arr[0]);

    rearrangeArray(arr, size);

    printf("Переставленный массив: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}

