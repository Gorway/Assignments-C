#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv) {

    if(argc != 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    FILE* file;

    file = fopen(argv[1], "w");
    if(file == NULL) {
        perror("Error creating file");
        return 1;
    }

    fprintf(file, "Some content in the file.\n");

    fclose(file);

    printf("File '%s' is created and filled with content.\n", argv[1]);

    file = fopen(argv[1], "r");
    if(file == NULL) {
        perror("Error opening file.\n");
        return 1;
    }

    char ch;
    
    printf("Content of the file '%s': \n", argv[1]);
    while((ch = fgetc(file)) != EOF) {
        putchar(ch);
    }

    fclose(file);

    if(remove(argv[1]) != 0) {
        perror("Error deleting file.\n");
        return 1;
    }

    printf("\nFile '%s' has been deleted.\n", argv[1]);

    return 0;
}




