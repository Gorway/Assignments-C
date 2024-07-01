#include <stdio.h>

int function(int num1, int  num2);

int main () 
{
    
    int n1 = 0;
    int n2 = 0;
    printf("Please enter two numbers: ");
    scanf("%d %d", &n1, &n2);
    function(n1,n2);
}

int function( int num1, int num2)
{
     int sum = 0;
    
     for (int i = num1; i <= num2; i++) {
         if(i % 2 == 0) {
             sum += i;
         }
     }
     printf("Sum of even number from %d to %d is %d\n", num1, num2, sum);
}
