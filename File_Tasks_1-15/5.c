#include <stdio.h>
#include <stdlib.h>

int main() {

    FILE* file = fopen("numbers.txt", "r");

    if(file == NULL) {
        printf("cannot open file\n");
        return 1;
    }

    char first_digit;

    first_digit = fgetc(file);

    if(first_digit >= '0' && first_digit <= '9') {
        printf("First digit in the file: %c\n", first_digit);
    } else {
        printf("No digit found in the file.\n");
    }

    fclose(file);
}
        

