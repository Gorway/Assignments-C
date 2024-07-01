#include <stdio.h>

int main () 
{
   int num1 = 0;
   int num2 = 0;

   printf("Enter two number ` ");
   scanf("%d %d", &num1, &num2);
   
   int total = num1 + num2;

   printf("Result = %d\n", total);

   return 0;
}
