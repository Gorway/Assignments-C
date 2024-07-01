#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]) {

    int count = argc;
    
    int* result = (int*)malloc(count * sizeof(int));
    
    for(int i = 1; i < count; i++) {
        result[i] = atoi(argv[i]);
        result[i] += 5;
    }

    for(int i = 0; i < count; i++) {
        printf(" %d", result[i]);
    }
    
    printf("\n");

    free(result);
}
