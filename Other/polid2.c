#include <stdio.h>
#include <string.h>

int main() {
    char str[100];

    // Ввод строки
    printf("Введите строку: ");
    scanf("%s", str);

    int len = strlen(str);
    int isPalindrome = 1; // Предполагаем, что строка является палиндромом

    // Проверка палиндрома без использования isPalindrome
    for (int i = 0; i < len / 2; ++i) {
        if (str[i] != str[len - i - 1]) {
            isPalindrome = 0; // Если символы не совпадают, строка не является палиндромом
            break;
        }
    }

    // Вывод результата
    if (isPalindrome) {
        printf("Строка является палиндромом.\n");
    } else {
        printf("Строка не является палиндромом.\n");
    }

    return 0;
}
