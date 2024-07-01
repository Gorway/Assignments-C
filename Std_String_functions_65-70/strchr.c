#include <stdio.h>

char* strchr_(const char*, char);

int main()
{
    const char string[] = "Hello, World";
    char character = 'W';
    
   // printf("%p", strchr_(string, character));
    char *result = strchr_(string, character);
      
    if(result != NULL) {
        printf("Symbol` %c founded in string: %s\n", character, string);
    } else { 
        printf("%c not founded in string:\n", character);
    }
    

}

char* strchr_(const char str[], char symbol)
{
    


    for(int i = 0; str[i] != '\0'; i++)
    {
        if(str[i] == symbol)
        { 
            return (char*)str + i;
        }
    }
    return  NULL;
}
