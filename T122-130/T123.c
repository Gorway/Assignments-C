// gcc -E <file.name>

#include <stdio.h>

#define MY_CODE \
    int main() \
    { \
        printf("Hello, World!\n"); \
        return 0; \
    }

#line 1 "MyCode"
MY_CODE

