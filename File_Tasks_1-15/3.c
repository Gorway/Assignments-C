#include <stdio.h>

int main() {
    FILE *file;
    int num;

    file = fopen("numbers.txt", "w");
    if (file == NULL) {
        printf("Cannot open file.\n");
        return 1;
    }
    int count = 10;

    printf("Enter numbers (enter -1 to end):\n");

    while (num != -1){
        printf("Enter a number: ");
        scanf("%d", &num);

        if (num == -1)
            break;

        fprintf(file, "%d\n", num);
        fseek(file, 0, SEEK_END);
   }

    fclose(file);

    printf("Numbers have been written to numbers.txt.\n");

    return 0;
}

