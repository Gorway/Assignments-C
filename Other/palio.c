#include <stdio.h>

int countDifferences(char array[]) {
    int diff_count = 0;

    for (int i = 0; array[i] != '\0'; i++) {
        int isUnique = 1;

        for (int j = 0; j < i; j++) {
            if (array[i] == array[j]) {
                isUnique = 0;
                break;
            }
        }

        if (isUnique) {
            diff_count++;
        }
    }

    return diff_count;
}

int main() {
    char myArray[] = "Hello, World";

    int result = countDifferences(myArray);

    printf("Количество различных элементов: %d\n", result);

    return 0;
}
