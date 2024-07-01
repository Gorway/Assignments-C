#include <stdio.h>
#include <stdlib.h>

int main() {

    const char* oldFilename = "example.txt";
    const char* newFilename = "replace.txt";

    if(rename(oldFilename, newFilename) != 0) {
        perror("Error renaming file.\n");
        return 1;
    }

    printf("File renamed successfully from '%s' to '%s .'\n", oldFilename,
    newFilename);

    return 0;
}
