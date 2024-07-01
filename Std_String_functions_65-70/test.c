#include <stdio.h>

char* strcpy_(char* dest, const char* src) {
    // Сохраняем начальный адрес dest для возврата
    char* original_dest = dest;

    // Копируем символы из src в dest, пока не достигнем конца строки
    while (*src != '\0') {
        *dest = *src;
        *dest++;
        *src++;
        // Продолжаем копирование
    }

    // Возвращаем указатель на начало строки dest
    return original_dest;
}

int main() {
    const char* source = "Hello, world!";
    char destination[50]; // предполагаем, что destination имеет достаточный размер

    strcpy_(destination, source);

    printf("Исходная строка: %s\n", source);
    printf("Скопированная строка: %s\n", destination);

    return 0;
}

