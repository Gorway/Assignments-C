#include <stdio.h>

// Функция для получения обратного числа
int reverse_number(int num) {
    int reversed = 0;
    while (num > 0) {
        reversed = reversed * 10 + num % 10;
        num /= 10;
    }
    return reversed;
}

// Функция для проверки, является ли число палиндромом
int is_palindrome(int num) {
    return num == reverse_number(num);
}

int main() {
    int num, iterations = 0;

    // Ввод числа
    printf("Введите число: ");
    scanf("%d", &num);

    // Пока число не станет палиндромом, добавляем к нему его обратное число
    while (!is_palindrome(num)) {
        int reversed = reverse_number(num);
        num += reversed;
        iterations++;
    }

    // Выводим палиндромное число и количество итераций
    printf("Палиндромное число: %d\n", num);
    printf("Количество итераций: %d\n", iterations);

    return 0;
}

