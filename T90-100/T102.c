#include <stdio.h>

int main() {
    // Объявляем массив массивов целых чисел
    int arrays[][5] = {
        {1, 1, 1, 1, 1},
        {1, 0, 1, 1, 1},
        {0, 0, 1, 0, 1},
        {1, 1, 1, 1, 0}
    };

    int num_arrays = sizeof(arrays) / sizeof(arrays[0]);

    // Проверяем каждый массив на наличие только единиц
    printf("Массивы только с единицами:\n");
    for (int i = 0; i < num_arrays; ++i) {
        int count_ones = 0;
        for (int j = 0; j < sizeof(arrays[i]) / sizeof(arrays[i][0]); ++j) {
            if (arrays[i][j] == 1) {
                count_ones++;
            }
        }
        if (count_ones == sizeof(arrays[i]) / sizeof(arrays[i][0])) {
            printf("{ ");
            for (int j = 0; j < sizeof(arrays[i]) / sizeof(arrays[i][0]); ++j) {
                printf("%d ", arrays[i][j]);
            }
            printf("}\n");
        }
    }

    return 0;
}

