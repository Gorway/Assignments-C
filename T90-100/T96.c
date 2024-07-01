#include <stdio.h>
#include <stdlib.h>

// Функция для добавления элемента в конец массива
int* addElement(int* array, int* size, int element) {
    // Увеличиваем размер массива
    (*size)++;
    
    // Создаем новый массив с увеличенным размером
    int* newArray = (int*)malloc((*size) * sizeof(int));

    // Копируем старые элементы в новый массив
    for (int i = 0; i < (*size) - 1; i++) {
        newArray[i] = array[i];
    }

    // Добавляем новый элемент в конец нового массива
    newArray[(*size) - 1] = element;

    // Освобождаем старый массив
    free(array);

    // Возвращаем новый массив
    return newArray;
}

int main() {
    int* dynamicArray = NULL;
    int size = 0;

    // Добавляем элементы в массив
    dynamicArray = addElement(dynamicArray, &size, 1);
    dynamicArray = addElement(dynamicArray, &size, 2);
    dynamicArray = addElement(dynamicArray, &size, 3);

    // Выводим массив
    printf("Массив: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", dynamicArray[i]);
    }
    printf("\n");

    // Освобождаем память
    free(dynamicArray);

    return 0;
}

