
#include <stdio.h>

char* strcpy_(char* dest, const char* src) {

    char* original_dest = dest;


    while (*src != '\0') {
        *dest = *src;
        *dest++;
        *src++;

    }


    return original_dest;
}

int main() {
    const char* source = "Hello, world!";
    char destination[50];

    strcpy_(destination, source);

    printf("Source string: %s\n", source);
    printf("Copied string: %s\n", destination);

    return 0;
}

