#include <stdio.h>
#include <ctype.h>

int main() {
    char str[100];
    
    printf("Введите строку: ");
    gets(str);
    
    for (int i = 0; str[i] != '\0'; i++) {
        str[i] = toupper(str[i]);
    }
    
    printf("Строка в верхнем регистре: %s\n", str);
    
    return 0;
}

