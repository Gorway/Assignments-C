#include <stdio.h>


int main ()
{
    int num1 = 0;
    int num2 = 0;

    printf("Enter two number` ");
    scanf("%d %d", &num1, &num2);

    if (num1 > num2)
    {
        printf("%d is higher\n", num1);

    } else if (num2 > num1)
    
    {
        printf("%d is higher\n", num2);
    }

    return 0;
}
