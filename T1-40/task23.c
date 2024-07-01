#include <stdio.h>


int main()
{
    int num = 0;

    printf("Enter number for multiplication table` ");
    scanf("%d", &num);

    printf("Multiplication table for %d\n", num);
   
    for (int i = 1; i <= 10; i++)
    { 
        printf("%d * %d = %d\n", num, i, num * i);
    }

    return 0;
}
