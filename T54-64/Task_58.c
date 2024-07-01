#include <stdio.h>

int function(int);


int main()
{
    int number = 0;

    printf("Enter number: ");
    scanf("%d", &number);
 
   if(function(number))
   {
       printf("%d  is Perfect number.\n", number);
   } else {
       printf("%d  is not Perfect number.\n", number);
   }

    return 0;
}

int function(int num) 
{
    int sum = 0;
    
    for (int i = 1; i <= num / 2; i++)
    {
        if (num % i == 0) {
            sum += i;
        }
    }


    return sum == num;
}

