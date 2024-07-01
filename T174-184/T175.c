#include <stdio.h>
#include <stdlib.h>

int main() {

    long size; 
    printf("Please enter size of array: ");
    scanf("%ld", &size);

    int* array = (int*)malloc(size * sizeof(int));

    if(array == NULL) {
        printf("Memory allocation failed\n"); 
    } else {
        printf("Memoty allocation success\n");
    }

    free(array);
}


