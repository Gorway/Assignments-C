#include <stdio.h>


int main() 
{
    int number = 0;
    int origNumber;
    int remainder;
    int sum = 0;

    printf("Please enter whole number: ");
    scanf("%d", &number);

    origNumber = number;

    while (number != 0) {
        remainder = number % 10;
        sum += remainder;
        number /= 10;
    }

    printf("Sum of number` %d equal to` %d\n", origNumber , sum);

    return 0;
}
