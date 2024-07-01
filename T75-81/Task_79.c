#include <stdio.h>

char low_to_uppercase(char);
void changeArray(char*);

int main()
{
    char string[] = "HELLO WOOOORLD";
    
    changeArray(string);

}

char low_to_uppercase(char symbol)
{
    if (symbol >= 'A' && symbol <= 'Z') {
    
        return symbol += 32;
    }
}

void changeArray(char* str)
{
    for(int i = 0; str[i] != '\0'; i++)
    {
        printf("%c", low_to_uppercase(str[i]));
    }
    printf("\n");
}

