#include <stdio.h>

int main() {
    int num1, num2;
    
    printf("Введите два числа: ");
    if (scanf("%d %d", &num1, &num2) != 2) {
        printf("Ошибка: Не удалось прочитать оба числа.\n");
        return 1;
    }

    if (num2 == 0) {
        printf("Ошибка: Нельзя делить на ноль.\n");
        return 2;
    }

    printf("%d / %d = %.2f\n", num1, num2, (float)num1 / num2);

    return 0;
}

