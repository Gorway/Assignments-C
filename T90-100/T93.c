#include <stdio.h>
#include <stdlib.h>

int* pullPrimes(int* arr, int size ) {
    
    int currentnumber = 0;

    int* primesArray = (int*) malloc ( size  * sizeof(int));
    
    for(int i = 0; i < size; i++) {
        int isPrime = 1;

        for(int j = 2; j * j <= arr[i]; j++) {
            if(arr[i] % j == 0) {
                isPrime = 0;
                break;
            }
        }

        if(isPrime) {
            primesArray[currenNumber] = arr[i];
            currentNumber++;
        }
    }

    return primesArray;
}
