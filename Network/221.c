#include <stdio.h>

#define ARRAY_SIZE 5

int global_var = 100;

void merge_arrays(int* ptr) {
    int local_array1[] = {1, 2, 3, 4, 5};
    int local_array2[] = {6, 7, 8, 9, 10};

    for (int i = 0; i < ARRAY_SIZE; i++) {
        ptr[i] = local_array1[i];
    }

 
    ptr[ARRAY_SIZE] = global_var;


    for (int i = 0; i < ARRAY_SIZE; i++) {
        ptr[ARRAY_SIZE + 1 + i] = local_array2[i];
    }
}

int main() {
    int result_array[ARRAY_SIZE * 3];

    merge_arrays(result_array);

    printf("Результирующий массив:\n");
    for (int i = 0; i < ARRAY_SIZE * 3; i++) {
        printf("%d ", result_array[i]);
    }
    printf("\n");

    return 0;
}

