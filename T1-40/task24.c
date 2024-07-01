#include <stdio.h>


int main()
{
    int num1 = 0;
    int num2 = 0;
    int sum = 0;

    printf("Enter first number` ");
    scanf("%d", &num1);

    printf("Enter second numbr` ");
    scanf("%d", &num2);

    for (int i = num1; i <= num2; i++) {

        if (i % 2 == 0) {

            sum += i;
        }
    }
    
    printf("Sum of even numbers from` %d to` %d is %d\n", num1, num2, sum);

    return 0;
}
