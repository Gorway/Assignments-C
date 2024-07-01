#include <stdio.h>


long  makePalindrome(long num) {
    long steps = 0;


    while (1) {
        // Функция для переворачивания числа
        long reversed = 0;
        long original = num;
        while (original > 0) {
            reversed = reversed * 10 + original % 10;
            original /= 10;
        }

        // Проверка, является ли число палиндромом
        if (num == reversed) {
            break; // Выход из цикла, если число стало палиндромом
        }

        num += reversed; // Прибавление к числу его перевернутой версии
        steps++;
    }

    return steps;
}

// Пример использования функции
long main() {
    long number;
    printf("Введите число: ");
    scanf("%ld", &number);

    long steps = makePalindrome(number);

    printf("Получен палиндром за %ld шагов.\n", steps);

    return 0;
}

