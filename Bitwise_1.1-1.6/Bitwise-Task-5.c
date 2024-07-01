#include <stdio.h>

int main() 
{
    char symb;

    printf("Enter a character: ");
    scanf("%c", &symb);

    char transformed_symb = symb;

    transformed_symb ^= (1 << 5);

    printf("Transformed %c --> %c\n", symb , transformed_symb);
}
