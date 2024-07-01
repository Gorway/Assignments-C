#include <stdio.h>

void printReverse(char* reverse_arr, int size) {
    for (int i = size - 1; i >= 0; i--) {
        printf("%c\n", reverse_arr[i]);
    }
}

int main() {
    char myArray[] = "Hello";
    int arraySize = sizeof(myArray) / sizeof(myArray[0]);

    printReverse(myArray, arraySize);

    return 0;
}

