#include <stdio.h>                                               // CALLOC
#include <stdlib.h>
#include <string.h>

// Простая пользовательская функция myCalloc
void* myCalloc(size_t numElements, size_t elementSize) {
    size_t totalSize = numElements * elementSize;

    // Выделение блока памяти с использованием malloc
    void* ptr = malloc(totalSize);

    if (ptr == NULL) {
        printf("Не удалось выделить память.\n");
        exit(1); // Выход из программы в случае ошибки выделения памяти
    }

    // Обнуление памяти с использованием memset
    memset(ptr, 0, totalSize);

    return ptr;
}

int main() {
    int* dynamicArray;

    // Использование пользовательской функции myCalloc
    dynamicArray = (int*)myCalloc(5, sizeof(int));

    // Ваш код для использования массива

    // Освобождение памяти
    free(dynamicArray);

    return 0;
}

                                                    //REALLOC


#include <stdio.h>
#include <stdlib.h>

// Простая пользовательская функция myRealloc
void* myRealloc(void* ptr, size_t newSize) {
    // Если указатель равен NULL, то это эквивалент вызову malloc(newSize)
    if (ptr == NULL) {
        return malloc(newSize);
    }

    // Если newSize равен 0, то это эквивалент вызову free(ptr)
    if (newSize == 0) {
        free(ptr);
        return NULL;
    }

    // Выделение нового блока памяти
    void* newPtr = malloc(newSize);

    // Проверка успешности выделения
    if (newPtr == NULL) {
        return NULL; // Не удалось выделить новую память
    }

    // Копирование данных из старого блока в новый
    memcpy(newPtr, ptr, newSize);

    // Освобождение старого блока
    free(ptr);

    return newPtr;
}

int main() {
    int* dynamicArray = (int*)malloc(5 * sizeof(int));

    // Использование пользовательской функции myRealloc
    int* resizedArray = (int*)myRealloc(dynamicArray, 10 * sizeof(int));

    // Вывод результата
    printf("Массив после перераспределения памяти: ");
    for (int i = 0; i < 10; i++) {
        printf("%d ", resizedArray[i]);
    }
    printf("\n");

    // Освобождение памяти
    free(resizedArray);

    return 0;
}

