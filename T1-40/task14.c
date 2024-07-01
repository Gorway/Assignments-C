#include <stdio.h>


int main() 
{
    char sym = 0;

    printf("Enter an uppercase letter`  ");
    scanf(" %c", &sym);
     
    if (sym >= 'A' && sym <= 'Z') 
    {
        sym = sym + 32;

       printf("The lowercase latter is`  %c\n", sym);

    } else {
        
        printf("You did not enter  an uppercase letter\n");
    }

    return 0;
}
