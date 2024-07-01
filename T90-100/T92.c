#include <stdio.h>
#include <stdlib.h>

int* evenNumbers(int);

int main()
{
    int n;
    printf("Please enter number: ");
    scanf("%d", &n);

    int *result = evenNumbers(n);

    printf("Even numbers: ");

    for(int i = 0; i < n; i++) {
       if(result[i] != 0) {
           printf("%d ", result[i]);
    }
}
    printf("\n");

    free(result);

    return 0;
}


int* evenNumbers(int n) {

    int* evenArray = (int*) malloc(n * sizeof(int));

    for(int i = 0; i < n; i++) {

        if(i % 2 == 0) {
            evenArray[i] = i;
        }
    }

    return evenArray;
}
