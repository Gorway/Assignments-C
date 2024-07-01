#include <stdio.h>
#include <stdlib.h>

int* pullNumbers(char*, int, int*);

int main() {

    char string[50];
    printf("Enter string: ");
    fgets(string, sizeof(string), stdin);
    
    int count = 0;
    int length = 0;
    for(int i = 0; string[i] != '\0'; i++) {
        length++;
    }

    int* newArray = pullNumbers(string, length, &count);

    printf("Numbers in Array is: ");

    for(int i = 0; i < count ; i++) {
        printf("%d ", newArray[i]);
    }

    printf("\n");

    free(newArray);

    return 0;


}

int* pullNumbers(char* str, int len, int* count ) {

    int* numArray = (int*) malloc(len * sizeof(int));
    
    if(numArray == NULL) {
        printf("Memory allocation Failed.\n");
        exit(1);
    }
   
   *count = 0;
   for(int i = 0; str[i] != '\0'; i++) {
        if(str[i] >= '0' && str[i] <= '9') {
            numArray[(*count)++] = str[i] - '0';
        }
    }
    
    numArray = (int*)realloc(numArray, *count * sizeof(int));

    return numArray;
}
