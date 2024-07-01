#include <stdio.h>

double calculateSquareRoot(double number) {
    if (number < 0) {
        fprintf(stderr, "Нельзя вычислить квадратный корень отрицательного числа.\n");
        return -1.0;
    }

    double result = 1.0;

    // Выполняем вычисление квадратного корня методом Ньютона
    for (int i = 0; i < 100; ++i) {
        result = 0.5 * (result + number / result);
        printf("result ----> %lf\n", result);
   }

    return result;
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

