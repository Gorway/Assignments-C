#include <stdio.h>

int isPalindrome(int num) {
    // Функция для проверки, является ли число палиндромом
    int reversed = 0;
    int original = num;

    while (num > 0) {
        int remainder = num % 10;
        reversed = reversed * 10 + remainder;
        num /= 10;
    }

    return original == reversed;
}

int stepsToPalindrome(int num) {
    int steps = 0;

    while (!isPalindrome(num)) {
        // Прибавляем к числу его перевернутое значение
        num += isPalindrome(num) ? 0 : reverseNumber(num);
        steps++;
    }

    return steps;
}

int reverseNumber(int num) {
    // Функция для получения перевернутого значения числа
    int reversed = 0;

    while (num > 0) {
        int remainder = num % 10;
        reversed = reversed * 10 + remainder;
        num /= 10;
    }

    return reversed;
}

int main() {
    // Пример использования функции
    int num;
    printf("Введите число: ");
    scanf("%d", &num);

    int result = stepsToPalindrome(num);

    printf("Количество шагов для получения палиндрома: %d\n", result);

    return 0;
}

