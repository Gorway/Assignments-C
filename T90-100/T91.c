#include <stdio.h>
#include <stdlib.h>

int* concatenateArrays(int*, int, int*, int);

int main() 
{
    int arr1[] = {0,1,2,3,4};
    int arr2[] = {5,6,7,8,9,10};

    int size1 = sizeof(arr1) / sizeof(arr1[0]);
    int size2 = sizeof(arr2) / sizeof(arr2[0]);

    
    int* ResultArray = concatenateArrays(arr1, size1, arr2, size2);

    printf("Concatenate Array: ");

    for(int i = 0; i < size1 + size2; i++) {
    printf("%d ", ResultArray[i]);
    }
    
    printf("\n");

    free(ResultArray);

    return 0; 
}


int* concatenateArrays(int *arr1, int size1, int* arr2, int size2) {
    
    int newsize = size1 + size2;

    int* newArray = (int*) malloc ( newsize * sizeof(int));

    if(newArray == NULL) {
        printf("Failed to allocate memory\n");
        exit(1);
    }

    for(int i = 0; i < size1; i++) {
        newArray[i] = arr1[i];
    }

    for(int i = 0 ; i < size2; i++) {
        newArray[size1 + i] = arr2[i];
    }

    return newArray;
}
