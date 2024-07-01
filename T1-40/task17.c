#include <stdio.h>


int main()
{
    int i = 0;

    printf("Enter any number` ");
    scanf("%d", &i);

    if (i % 2 == 0) 
    {
        printf("The` %d is even\n", i);

    } else { 

        printf("The` %d is odd\n", i);
    }
    
    return 0;
}
