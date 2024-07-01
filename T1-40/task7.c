#include <stdio.h>


int main()
{
    float num1 = 0;
    float num2 = 0;

    printf("Enter two float number `");
    scanf("%f %f", &num1, &num2);

    float result = num1 + num2;
     
    printf("Result = %f\n", result);

    return 0;
}
