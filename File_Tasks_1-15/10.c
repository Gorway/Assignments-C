#include <stdio.h>
#include <stdlib.h>

int main() {

    FILE* file;

    file = fopen("newfile.txt", "a+");
    if(file == NULL) {
        perror("Error opening file.\n");
        return 1;
    }

    fclose(file);

    file = fopen("newfile.txt", "r+");
    if(file == NULL) {
        perror("Error opening file.\n");
        return 1;
    }


    if(fseek(file, 0, SEEK_SET) != 0) {
        perror("Error resetting file pointer\n");
        fclose(file);
        return 1;
    }

    if(fprintf(file, "Hello ") < 0) {
        perror("Error writing to file.\n");
        fclose(file);
        return 1;
    }

    fclose(file);

    printf("Word 'Hello' has been added to the begining of the file.\n");

    return 0;
}
