#include <stdio.h>

int findMissingNumber(int arr[], int n) {

    int expectedSum = (n + 1) * (n + 2) / 2;


    int actualSum = 0;
    for (int i = 0; i < n; i++) {
        actualSum += arr[i];
    }


    return expectedSum - actualSum;
}

int main() {
    int n;
    printf("Введите размер массива (n): ");
    scanf("%d", &n);


    if (n < 2) {
        printf("Ошибка: недопустимый размер массива.\n");
        return 1;
    }

    int arr[n - 1];
    printf("Введите %d уникальных цифр для массива:\n", n - 1);
    for (int i = 0; i < n - 1; i++) {
        scanf("%d", &arr[i]);
    }


    int missingNumber = findMissingNumber(arr, n - 1);
    printf("Недостающая цифра: %d\n", missingNumber);

    return 0;
}

