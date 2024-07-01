#include <stdio.h>


int main() 
{
    int num1 = 0;
    int num2 = 0;
    int num3 = 0;
    float average = 0;

    printf("Please enter three whole numbers` ");
    scanf("%d %d %d", &num1, &num2, &num3);

    average = (num1 + num2 + num3) / 3;

    printf("The average of three whole numbers is` %.2f\n", average);

    return 0;
}

