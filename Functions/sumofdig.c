#include <stdio.h>

int sumEvenDigits(int a, int b) {
    int start = (a < b) ? a : b;
    int end = (a > b) ? a : b;
    int sum = 0;

    for (int i = start; i <= end; ++i) {
        int num = i;
        while (num != 0) {
            int digit = num % 10;
            if (digit % 2 == 0) {
                sum += digit;
            }
            num /= 10;
        }
    }

    return sum;
}

int main() {
    int num1, num2;
    printf("Enter two numbers: ");
    scanf("%d %d", &num1, &num2);

    int result = sumEvenDigits(num1, num2);

    printf("Sum of even digits between %d and %d: %d\n", num1, num2, result);

    return 0;
}

