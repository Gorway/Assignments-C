#include <stdio.h>

char*strcat_(char*, const char*);

int main()
{
    const char source[] = " in this World";
    char destination[50] = "Hello everyone";
    
    strcat_(destination, source);

    printf("Concataneted string: %s\n", destination);

}

char*strcat_(char * dest, const char* src)
{   

    char *ptr = dest;
    while(*ptr != '\0')
    {
        ptr++;
    }

    while(*src != '\0')
    {
        *ptr = *src;
        ptr++;
        src++;
    }

    *ptr = '\0';
    
    return dest;
}
