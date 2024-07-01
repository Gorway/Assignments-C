#include <stdio.h>

void decimalToHex(int decimalNumber) {
    char hexNumber[20];
    int index = 0;

    // Переводим в шестнадцатеричную систему
    while (decimalNumber != 0) {
        int remainder = decimalNumber % 16;

        // Преобразуем остаток в символ
        if (remainder < 10) {
            hexNumber[index] = remainder + '0';
        } else {
            hexNumber[index] = remainder - 10 + 'A';
        }

        index++;
        decimalNumber /= 16;
    }

    // Выводим результат в обратном порядке
    printf("Шестнадцатеричное представление: ");
    for (int i = index - 1; i >= 0; i--) {
        printf("%c", hexNumber[i]);
    }
    printf("\n");
}

int main() {
    int decimalNumber;

    // Вводим десятичное число
    printf("Введите десятичное число: ");
    scanf("%d", &decimalNumber);

    // Вызываем функцию для перевода в шестнадцатеричную систему
    decimalToHex(decimalNumber);

    return 0;
}

