#include <stdio.h>
#include <stdlib.h>

int main() {
    char command[10];


    printf("Enter Programm name: ");
    scanf("%s", command);


    if (system(command) == -1) {
        perror("Error.");
        return 1;
    }

    return 0;
}

