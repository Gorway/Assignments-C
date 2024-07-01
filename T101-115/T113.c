#include <stdio.h>

double calculateSquareRoot(double number) {
    if (number < 0) {
        fprintf(stderr, "Нельзя вычислить квадратный корень отрицательного числа.\n");
        return -1.0;
    }

    double low = 0.0;
    double high = number;
    double mid = (low + high) / 2.0;

    // Выполняем бинарный поиск для приближенного вычисления
    for (int i = 0; i < 100; ++i) {
        if (mid * mid > number) {
            high = mid;
        } else {
            low = mid;
        }

        mid = (low + high) / 2.0;
    }

    return mid;
}

int main() {
    double number;

    // Вводим число
    printf("Введите число: ");
    scanf("%lf", &number);

    // Вызываем функцию, выводим результат
    double squareRoot = calculateSquareRoot(number);

    if (squareRoot >= 0) {
        printf("Квадратный корень из %lf равен %lf\n", number, squareRoot);
    }

    return 0;
}

