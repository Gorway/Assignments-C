#include <stdio.h>

// Функция для замены символов в массиве char их соответствующими цифрами от 0 до 25
void replaceWithDigits(char *str, int (*charToDigit)(char)) {
    while (*str) {
        if (*str != ' ') {  // Пропускаем пробелы
            int digit = charToDigit(*str);
            if (digit >= 0 && digit <= 25) {
                *str = 'A' + digit;  // Заменяем символ его ASCII-значением
            }
        }
        ++str;
    }
}

// Функция для преобразования символа в цифру от 0 до 25
int charToDigit(char c) {
    return (int)(c - 'A');
}

int main() {
    char inputString[] = "HELLO WORLD";
    printf("Исходная строка: %s\n", inputString);

    // Вызов функции для замены символов в массиве char
    replaceWithDigits(inputString, charToDigit);

    // Вывод результата
    printf("Результат: %s\n", inputString);

    return 0;
}

