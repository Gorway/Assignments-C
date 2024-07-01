#include <stdio.h>


int sumArray(int arr[], int size) {

    if (size == 0) {
        return 0;
    } else {

        return arr[size - 1] + sumArray(arr, size - 1);
    }
}


double averageArray(int arr[], int size) {

    int sum = sumArray(arr, size);


    return size > 0 ? (double)sum / size : 0.0;
}

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    int size = sizeof(arr) / sizeof(arr[0]);


    double result = averageArray(arr, size);


    printf("Среднее арифметическое массива: %.2f\n", result);

    return 0;
}

