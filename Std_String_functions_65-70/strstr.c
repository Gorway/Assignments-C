#include <stdio.h>

char* strstr_(const char*, const char*);

int main()
{
    const char string[] = "Hello everyone in this world";
    const char word[] = "this";
    char* result = strstr_(string, word);

    if(result) {
        printf("Enter point: %s\n", result);
    } else { 
        printf("Can not found enter point.\n");
    }

}

char* strstr_(const char string[], const char word[])
{
    while(*string) {
        const char* s = string;
        const char* w = word;

        while(*s && *w && (*s == *w)) {
            s++;
            w++;
        }

        if(*w == '\0') {
            return (char*)string;
        }

        string++;
    }

    return NULL;
}
