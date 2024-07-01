#include <stdio.h>
#include <stdlib.h>

void replace(const char* filename) {

    FILE* file = fopen(filename, "r+");
    if(file == NULL) {
        perror("Error opening file.\n");
        return;
    }

    int  ch;

    while((ch = getc(file)) != EOF) {
        if(ch == '.') {
            fseek(file, -1, SEEK_CUR);
            fputc('!', file);
        }
    }

    fclose(file);
}


int main() {

    const char* filename = "example.txt";

    replace(filename);

    FILE* file = fopen(filename, "r");
    if(file == NULL) {
        perror("Error opening file.\n");
        return 1;
    }

    int ch;

    while((ch = fgetc(file)) != EOF) {
        putchar(ch);
    }

    fclose(file);

    return 0;
    }
