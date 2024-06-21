#include <stdio.h>

int main()
{
    int number = 0;
    int power_of_two = 0;

    printf("Enter number: ");
    scanf("%d", &number);

    printf("Enter number of two: ");
    scanf("%d", &power_of_two);


    int result = 0;
    int original_number = number;
  
    result = number << 1;
  
    printf("%d multiplied by %d is %d\n", number, power_of_two, result);
    
    result = original_number >> 1;

    printf("%d divided by %d is %d\n", number, power_of_two, result);

}
