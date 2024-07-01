#include <stdio.h>
#include <string.h>

// Функция для печати строки наоборот
void print_reverse(const char *str) {
    if (*str == '\0') {
        return;
    }
    print_reverse(str + 1);
    putchar(*str);
}

int main() {
    char str[] = "Hello, World!";
    printf("Исходная строка: %s\n", str);
    printf("Строка наоборот: ");
    print_reverse(str);
    putchar('\n');
    return 0;
}

