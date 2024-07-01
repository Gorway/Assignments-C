#include <stdio.h>


int main() 
{
    int num = 4637;

    int prod = 1;

    while(num != 0)
    {
        prod *= num % 10;
        num /= 10;
    }

    int sum = 0;

    while(num != 0)
    {
        sum += num / 10;
        num /= 10;
    }


    printf("(%d*%d*%d*%d) - (%d+%d+%d+%d)  = %d\n", 4,6,3,7,4,6,3,7,
    prod-sum);

    return 0;
}
