#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int countWords(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Ошибка: Не удалось открыть файл.\n");
        return -1;
    }

    int wordCount = 0;
    int inWord = 0; // Флаг, указывающий, находимся ли мы внутри слова

    int c;
    while ((c = fgetc(file)) != EOF) {
        if (isspace(c)) {
            inWord = 0;
        } else if (!inWord) {
            inWord = 1;
            wordCount++;
        }
    }

    fclose(file);
    return wordCount;
}

int main() {
    char filename[100];
    
    // Запрос имени файла у пользователя
    printf("Введите имя файла: ");
    scanf("%s", filename);

    int words = countWords(filename);
    if (words >= 0) {
        printf("Количество слов в файле: %d\n", words);
    }

    return 0;
}

