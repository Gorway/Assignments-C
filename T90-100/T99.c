#include <stdio.h>
#include <stdlib.h>

int* extractDuplicates(const int* arr, int size, int* newSize) {
    int* duplicatesArr = NULL;
    int count = 0;

    for (int i = 0; i < size - 1; i++)
        for (int j = i + 1; j < size; j++)
            if (arr[i] == arr[j]) {
                duplicatesArr = (int*)realloc(duplicatesArr, (count + 1) * sizeof(int));
                if (duplicatesArr == NULL) {
                    printf("Memory allocation failed.\n");
                    exit(1);
                }
                duplicatesArr[count++] = arr[i];
                break; // Прерываем внутренний цикл после нахождения дубликата
            }

    *newSize = count;
    return duplicatesArr;
}

int main() {
    int arr[] = {2, 4, 6, 8, 2, 4, 10, 12, 14, 6};
    int size = sizeof(arr) / sizeof(arr[0]);

    int newSize;
    int* duplicatesArr = extractDuplicates(arr, size, &newSize);

    printf("Дубликаты: ");
    for (int i = 0; i < newSize; i++)
        printf("%d ", duplicatesArr[i]);

    printf("\n");

    free(duplicatesArr);

    return 0;
}

