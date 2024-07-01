#include <stdio.h>

int atoi(const char *str) {
    int result = 0;
    int sign = 1;
    int i = 0;

    // Пропускаем начальные пробелы
    while (str[i] == ' ') {
        i++;
    }

    // Определяем знак числа
    if (str[i] == '-' || str[i] == '+') {
        sign = (str[i++] == '-') ? -1 : 1;
    }

    // Преобразование строки в целое число
    while (str[i] >= '0' && str[i] <= '9') {
        result = result * 10 + (str[i++] - '0');
    }

    return result * sign;
}

int main() {
    const char *str = "-12345";
    int num = atoi(str);
    printf("Результат: %d\n", num);
    return 0;
}

