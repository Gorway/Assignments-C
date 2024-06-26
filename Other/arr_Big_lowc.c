#include <stdio.h>

int main() {
    int n;

    // Введите размер массива
    printf("Введите размер массива: ");
    scanf("%d", &n);
    // Проверка на неположительное значение n
    if (n <= 0) {
        printf("Размер массива должен быть положительным числом.\n");
        return 1;
    }

    // Объявление массива
    int arr[n];

    // Ввод элементов массива
    printf("Введите элементы массива:\n");
    for (int i = 0; i < n; ++i) {
        printf("Элемент %d: ", i + 1);
        scanf("%d", &arr[i]);
    }

    // Инициализация переменных для максимума и минимума
    int max = arr[0];
    int min = arr[0];

    // Поиск максимума и минимума
    for (int i = 1; i < n; ++i) {
        if (arr[i] > max) {
            max = arr[i];
        }
        if (arr[i] < min) {
            min = arr[i];
        }
    }

    // Вывод максимума и минимума
    printf("Максимальное значение: %d\n", max);
    printf("Минимальное значение: %d\n", min);

    return 0;
}
