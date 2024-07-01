#include <stdio.h>
#include <string.h>

#define CONCATENATE_STRINGS(a, b) ({ \
    char result[100]; \
    strcpy(result, a); \
    strcat(result, b); \
    result; \
})

int main() {
    // Используем макрос-функцию CONCATENATE_STRINGS для конкатенации строк
    const char* concatenated = CONCATENATE_STRINGS("Hello, ", "World!");

    // Вывод результата
    printf("Concatenated: %s\n", concatenated);

    return 0;
}

