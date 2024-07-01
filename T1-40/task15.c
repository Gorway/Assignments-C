#include <stdio.h>


int main() 
{
    char sym = 0;

    printf("Enter symbol ");
    scanf(" %c", &sym);

    if (sym >= '0' && sym <= '9') {

        printf("True\n");

    } else { 

        printf("False\n");
    }

    return 0;
}
