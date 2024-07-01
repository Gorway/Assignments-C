#include <stdio.h>
#include <stdlib.h>


int main(int argc, char* argv[]) {

    int count = argc;
    int result = 0;

    for(int i = 0; i < count; i++) {
         result += atoi(argv[i]);
    }

    printf("Sum of arguments: %d\n", result);
}
