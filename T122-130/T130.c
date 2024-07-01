#include <stdio.h>
#include <string.h>

// Структура для представления машины (Car)
struct Car {
    char brand[50];
    char model[50];
    int manufacturingYear;
};

// Функция для вывода информации о машине
void printCarInfo(struct Car car) {
    printf("Brand: %s\n", car.brand);
    printf("Model: %s\n", car.model);
    printf("Manufacturing Year: %d\n", car.manufacturingYear);
}

// Функция для категоризации элементов массива Car
void categorizeCars(struct Car cars[], int size) {
    for (int i = 0; i < size; ++i) {
        if (strcmp(cars[i].brand, "Mercedes") == 0) {
            printf("Car %d belongs to Mercedes brand.\n", i + 1);
        }
    }
}

int main() {
    // Создание и инициализация массива из трех машин
    struct Car cars[3] = {
        {"Toyota", "Camry", 2020},
        {"Mercedes", "E-Class", 2021},
        {"Honda", "Civic", 2019}
    };

    // Вывод информации о каждой машине
    for (int i = 0; i < 3; ++i) {
        printf("Car %d:\n", i + 1);
        printCarInfo(cars[i]);
        printf("\n");
    }

    // Категоризация машин по бренду
    categorizeCars(cars, 3);

    return 0;
}

