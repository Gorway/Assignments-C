#include <stdio.h>


int main()
{
    int x = 0;
    int y = 0;
    long long result = 1;

    printf("Please enter the value of x : ");
    scanf("%d", &x);

    printf("Please enter the value of y: ");
    scanf("%d", &y);

    for (int i = 0; i < y; i++) {
        result *= x;
    }

    printf("%d rased to the power of %d is equal to %lld\n", x, y, result);
   
   return 0;
}  
