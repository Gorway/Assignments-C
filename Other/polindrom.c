#include <stdio.h>

int isPalindrome(char str[]) {
    int start = 0;                   // Индекс начала строки
    int end = 0;                     // Индекс конца строки
    while (str[end] != '\0') {
        end++;                       // Найти конец строки
    }
    end--;                           // Установить индекс конца строки на последний символ

    while (start < end) {
        if (str[start] != str[end]) {
            return 0;                // Если символы не совпадают, это не палиндром
        }
        start++;
        end--;
    }
    return 1;                        // Если все символы совпадают, это палиндром
}

int main() {
    char input[100];
    
    printf("Введите строку: ");
    scanf("%s", input);

    if (isPalindrome(input)) {
        printf("Строка является палиндромом.\n");
    } else {
        printf("Строка не является палиндромом.\n");
    }

    return 0;
}
