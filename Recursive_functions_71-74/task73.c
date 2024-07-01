#include <stdio.h>

int sumofdigits(int);

int main()
{
    int number = 0;
    printf("Please enter number: ");
    scanf("%d", &number);
    
    int res = sumofdigits(number);
    printf("Sum of the digits of number`%d = %d\n", number, res);
}

int sumofdigits(int num)
{
    if(num == 0) {
        return 0;
    }
  int sum = num % 10;

  return sum + sumofdigits(num / 10);
}
