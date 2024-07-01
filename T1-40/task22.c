#include <stdio.h>


int main()
{    
    int i = 2;
    int num = 0;

    printf("Enter any number` ");
    scanf("%d", &num);

    i = 2;
    while (i < num)
    {
        if (num % i == 0) {

            printf("%d is Composit\n", num);
            
            break;

       } else if (num % i != 0) {

            printf("%d is Prime\n", num);

            break;
       }

    }

    return 0;
}

