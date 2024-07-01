#include <stdio.h>

int main()
{
    int num1 = 10;
    int num2 = 20;

    int* ptr1 = &num1;
    int* ptr2 = &num2;

    int result1 = *ptr1 + *ptr2;
    printf("Result = %d\n", result1);
   
    int result2 = *ptr1 - *ptr2;
    printf("Result = %d\n", result2);

    return 0;

}
