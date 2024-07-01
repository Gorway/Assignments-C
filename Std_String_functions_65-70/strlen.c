#include <stdio.h>

char* my_strlen(const char*); 

int main() 
{
    char string[] = "Hello, World";
    
    char *lenght = my_strlen(string);
    printf("String lenght is`%d\n", (int)lenght);

}


char* my_strlen(const char* str) {

    const char * len = str;
    while(*len) {
        ++len;
    }

    return (char*)(len - str);
}







/* int* strlen(const char str[])
{
    int  lenght;
    int* ptr = &lenght;

    for(int i = 0; str[i] != '\0'; i++)
    {
        (*ptr)++;
    }

    return  *ptr;
}
*/
