#include <stdio.h>
#define FINDMAX(arr,size) \
({int max = arr[0]; \
    for (int i = 0; i < size; i++) { \
        if(arr[i] > max) \
        {max = arr[i]; } } max;})


int main() {
    int arr[] = {1,2,3};
    int size = sizeof(arr) / sizeof(arr[0]);

    int maxElement = FINDMAX(arr, size);

    printf("%d\n", maxElement);
}
