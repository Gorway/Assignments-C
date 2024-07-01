#include <stdio.h>

int sum_of_dividers(int);

int main()
{
    printf("Please enter number: ");
    int num = 0;
    scanf("%d", &num);

    int result  = sum_of_dividers(num);

    printf("Sum of number` %d dividers(except the number itself) equal = %d\n", num, result);

}

int sum_of_dividers(int num)
{
    int sum = 0;

    for(int divider = 1; divider <= num / 2; divider++)   {
        if(num % divider == 0)
        {
        sum += divider;
    } 
  }
    return sum;
}
