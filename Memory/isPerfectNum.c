#include <stdio.h>

// Функция для проверки идеального числа
int isPerfectNumber(int n) {
    int sum = 1; // Инициализируем сумму как 1, потому что 1 всегда является делителем

    // Проверяем делители числа до его корня
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            sum += i;
            if (i != n / i) {
                sum += n / i;
            }
        }
    }

    // Если сумма делителей равна числу, то число является идеальным
    return sum == n;
}

int main() {
    int number;

    // Вводим число, которое нужно проверить
    printf("Введите число: ");
    scanf("%d", &number);

    // Проверяем число на идеальность и выводим результат
    if (isPerfectNumber(number)) {
        printf("%d - идеальное число\n", number);
    } else {
        printf("%d - не идеальное число\n", number);
    }

    return 0;
}

