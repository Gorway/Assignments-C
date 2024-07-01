#include <stdio.h>
long factorial(int);

int main()
{
    int number = 0;
    printf("Enter a number to calculate the factorial: ");
    scanf("%d", &number);
    
    long result = factorial(number);

    printf("%d! =  %ld\n", number, result);
}

long factorial(int num)
{
    if(num == 0) {
        return 1;
        } 

    return num * factorial(num - 1);
}
