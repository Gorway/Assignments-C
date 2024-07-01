#include <stdio.h>

int fnct(int x);

int main()
{
    int num = 0; 
    printf("Please enter number:");
    scanf("%d", &num); 
    fnct(num) ;   
    
}

int fnct(int x) 
{  

   int i = 2;

    while(i < x) {
        if(x % i == 0) {
            printf("%d is Composite\n", x);
            break;
      } else  if (i % x != 0) {
            printf("%d is Prime\n", x);
            break;
       }
}      return x;
}

