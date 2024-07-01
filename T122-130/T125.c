#include <stdio.h>

#define CONCAT(a,b) a ## b


int main() {
    
    printf("Concatenated: %d\n", CONCAT(12,34));

    return 0;
}

