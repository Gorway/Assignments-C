#include <stdio.h>


int main()
{
    float celsius = 0;

    printf("Enter celsius degree ` ");
    scanf("%f", &celsius);

    float fahrenheit = (celsius * 9 / 5) + 32 ;

    printf("Fahrenheit = %.2f\n", fahrenheit);

    return 0;
}

