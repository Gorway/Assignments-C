#include <stdio.h>
#include <pthread.h>

// Структура для передачи аргументов в поток
struct numbers {
    double num1;
    double num2;
    double addition;
    double subtraction;
    double division;
    double multiplication;
};

// Функция для сложения чисел
void *addition(void *arg) {
    struct numbers *nums = (struct numbers *)arg;
    nums->addition = nums->num1 + nums->num2;
    return NULL;
}

// Функция для вычитания чисел
void *subtraction(void *arg) {
    struct numbers *nums = (struct numbers *)arg;
    nums->subtraction = nums->num1 - nums->num2;
    return NULL;
}

// Функция для деления чисел
void *division(void *arg) {
    struct numbers *nums = (struct numbers *)arg;
    if (nums->num2 != 0) {
        nums->division = nums->num1 / nums->num2;
    }
    return NULL;
}

// Функция для умножения чисел
void *multiplication(void *arg) {
    struct numbers *nums = (struct numbers *)arg;
    nums->multiplication = nums->num1 * nums->num2;
    return NULL;
}

int main() {
    pthread_t add_thread, sub_thread, div_thread, mul_thread;
    struct numbers nums = {10.0, 5.0, 0.0, 0.0, 0.0, 0.0}; // Пример чисел для арифметических операций

    // Создаем потоки для каждой операции
    pthread_create(&add_thread, NULL, addition, (void *)&nums);
    pthread_create(&sub_thread, NULL, subtraction, (void *)&nums);
    pthread_create(&div_thread, NULL, division, (void *)&nums);
    pthread_create(&mul_thread, NULL, multiplication, (void *)&nums);

    // Ждем завершения потоков
    pthread_join(add_thread, NULL);
    pthread_join(sub_thread, NULL);
    pthread_join(div_thread, NULL);
    pthread_join(mul_thread, NULL);

    // Выводим результаты арифметических операций
    printf("Результат сложения: %.2lf\n", nums.addition);
    printf("Результат вычитания: %.2lf\n", nums.subtraction);
    if (nums.num2 != 0) {
        printf("Результат деления: %.2lf\n", nums.division);
    } else {
        printf("Деление на ноль\n");
    }
    printf("Результат умножения: %.2lf\n", nums.multiplication);

    return 0;
}

