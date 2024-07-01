#include <stdio.h>

int main() {

    FILE* file;
    char filename[100];

    printf("Enter file name: ");
    scanf("%s", filename);

    file = fopen(filename , "r");

    if(file == NULL) {
        printf("Error. Could not open file.\n");
        return 1;
    }

    printf("File opened  successfully!\n");

    fclose(file);
    return 0;
}
