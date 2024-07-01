#include <stdio.h>
#include <unistd.h>

int main() {
    char filename[100];
    long size, current_size;

    // Запрос имени файла у пользователя
    printf("Введите имя файла: ");
    scanf("%s", filename);

    // Запрос нового размера у пользователя
    printf("Введите новый размер файла в байтах: ");
    scanf("%ld", &size);

    // Открытие файла для чтения и получение текущего размера
    FILE *file = fopen(filename, "rb");
    if (file == NULL) {
        printf("Ошибка: Не удалось открыть файл.\n");
        return 1;
    }
    
    // Определение текущего размера файла
    fseek(file, 0L, SEEK_END);
    current_size = ftell(file);
    fclose(file);

    // Проверка, нужно ли изменять размер файла
    if (size > current_size) {
        // Открытие файла для усечения до нового размера
        if (truncate(filename, size) == -1) {
            printf("Ошибка: Не удалось изменить размер файла.\n");
            return 1;
        }

        printf("Размер файла был успешно увеличен.\n");
    } else {
        printf("Размер файла не требует изменений.\n");
    }

    return 0;
}

