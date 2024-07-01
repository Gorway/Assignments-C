#include <stdio.h>

//void function(char* array);

int main() {

    const int size = 50;
    char arr[size];
    scanf("%s", arr);

    int lenght = 0;

    for (int i = 0 ; arr[i] != '\0'; i++) {
       
       lenght++;
       
    }

    printf("%d\n", lenght);
}

