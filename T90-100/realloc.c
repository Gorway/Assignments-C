#include <stdio.h>
#include <stdlib.h>

void* customRealloc(void *ptr, size_t newSize) {
    // Если указатель равен NULL, это аналог malloc
    if (ptr == NULL) {
        return malloc(newSize);
    }

    // Выделение нового блока памяти
    void *newBlock = malloc(newSize);

    if (newBlock == NULL) {
        // Обработка ошибки выделения памяти
        fprintf(stderr, "Ошибка выделения памяти.\n");
        return NULL;
    }

    // Копирование данных из старого блока в новый
    size_t oldSize = malloc_usable_size(ptr);
    if (newSize < oldSize) {
        oldSize = newSize;  // Если новый размер меньше старого, обрежем данные
    }
    
    for (size_t i = 0; i < oldSize; i++) {
        ((char*)newBlock)[i] = ((char*)ptr)[i];
    }

    // Освобождение старого блока памяти
    free(ptr);

    return newBlock;
}

int main() {
    // Пример использования кастомной функции realloc
    int *dynamicArray = (int*)malloc(5 * sizeof(int));

    for (int i = 0; i < 5; i++) {
        dynamicArray[i] = i + 1;
    }

    // Увеличение размера массива
    dynamicArray = customRealloc(dynamicArray, 10 * sizeof(int));

    // Вывод результатов
    printf("Dynamic Array: ");
    for (int i = 0; i < 10; i++) {
        printf("%d ", dynamicArray[i]);
    }
    printf("\n");

    // Освобождение памяти
    free(dynamicArray);

    return 0;
}

