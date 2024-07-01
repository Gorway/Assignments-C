#include <stdio.h>


int main() 
{
    float height = 0;
    float weight = 0;
    float BMI = 0;

    printf("Please enter your height and weight` ");
    scanf("%f %f", &height, &weight);

    BMI = weight / (height * height);

    printf("your BMI = %.2f\n", BMI);

    return 0;
}
