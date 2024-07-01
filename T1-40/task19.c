#include <stdio.h>


int main ()
{
    int num1 = 0;
    int num2 = 0;

    printf("Enter two number ` ");
    scanf("%d %d", &num1, &num2);

    if (num2 != 0 && num1 % num2 == 0)
    {
       printf("%d can be divided on %d\n", num1, num2);
   
    } else {

        printf("%d can not be divided on %d\n", num1, num2);
    }

    return 0;
}

