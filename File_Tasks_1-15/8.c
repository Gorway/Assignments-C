#include <stdio.h>
#include <stdlib.h>

#define SIZE 1000

int main() {

    FILE* file;
    char content[SIZE];
    int i = 0;

    file = fopen("numbers.txt", "r");

    while((content[i] = fgetc(file)) != EOF) {
        i++;

        if(i >= SIZE -1) {
            printf("File is too large.\n");
            fclose(file);
            return 1;
        }
    }

    content[i] = '\0';

    fclose(file);

    printf("Content of the file:\n%s\n", content);

    return 0;
}


