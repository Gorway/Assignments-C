#include <stdio.h>

int function(int);

int main()
{
    int number;

    printf("Please enter whole number: ");
    scanf("%d", &number);
    int original_number = number;
 printf("Sum of %d number equal to` %d\n", original_number,function(number));
    
    return 0;
}

int function(int number)
{
    int reminder = 0;
    int sum = 0;

    while(number != 0) {
        reminder = number % 10;
        sum += reminder;
        number /= 10;
     }
     return sum;
}
