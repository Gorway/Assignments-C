#include <stdio.h>


typedef int (*Operation)(int, int);


int add(int a, int b) {
    return a + b;
}

int subtract(int a, int b) {
    return a - b;
}

int multiply(int a, int b) {
    return a * b;
}

int divide(int a, int b) {
    if (b != 0) {
        return a / b;
    } else {
        printf("Ошибка: нельзя делить на 0.\n");
        return 0;
    }
}

int main() {
  
    Operation operation;

 
    int choice;
    printf("Выберите операцию:\n");
    printf("1. Сложение\n");
    printf("2. Вычитание\n");
    printf("3. Умножение\n");
    printf("4. Деление\n");
    scanf("%d", &choice);


    switch (choice) {
        case 1:
            operation = add;
            break;
        case 2:
            operation = subtract;
            break;
        case 3:
            operation = multiply;
            break;
        case 4:
            operation = divide;
            break;
        default:
            printf("Ошибка: неверный выбор операции.\n");
            return 1;
    }


    int operand1, operand2;
    printf("Введите два операнда: ");
    scanf("%d %d", &operand1, &operand2);


    int result = operation(operand1, operand2);


    printf("Результат: %d\n", result);

    return 0;
}

