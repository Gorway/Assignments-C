#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void compareAndWriteToFile(const char *file1Name, const char *file2Name, const char *outputFileName) {
    FILE *file1 = fopen(file1Name, "r");
    FILE *file2 = fopen(file2Name, "r");
    FILE *outputFile = fopen(outputFileName, "w");

    if (file1 == NULL || file2 == NULL || outputFile == NULL) {
        perror("Error opening files");
        return;
    }

    char word[100]; // Предполагаем максимальную длину слова 100 символов
    char wordList1[100][100]; // Массив для хранения слов из первого файла
    char wordList2[100][100]; // Массив для хранения слов из второго файла
    int count1 = 0, count2 = 0;

    // Считываем слова из первого файла
    while (fscanf(file1, "%s", word) != EOF) {
        strcpy(wordList1[count1], word);
        count1++;
    }

    // Считываем слова из второго файла
    while (fscanf(file2, "%s", word) != EOF) {
        strcpy(wordList2[count2], word);
        count2++;
    }

    // Проверяем слова из первого файла
    for (int i = 0; i < count1; i++) {
        int found = 0;
        for (int j = 0; j < count2; j++) {
            if (strcmp(wordList1[i], wordList2[j]) == 0) {
                found = 1;
                break;
            }
        }
        if (!found) {
            fprintf(outputFile, "%s\n", wordList1[i]);
        }
    }

    // Проверяем слова из второго файла
    for (int i = 0; i < count2; i++) {
        int found = 0;
        for (int j = 0; j < count1; j++) {
            if (strcmp(wordList2[i], wordList1[j]) == 0) {
                found = 1;
                break;
            }
        }
        if (!found) {
            fprintf(outputFile, "%s\n", wordList2[i]);
        }
    }

    fclose(file1);
    fclose(file2);
    fclose(outputFile);

    printf("Comparison completed. Results saved in '%s'.\n", outputFileName);
}

int main() {
    const char *file1Name = "file1.txt";
    const char *file2Name = "file2.txt";
    const char *outputFileName = "result.txt";

    compareAndWriteToFile(file1Name, file2Name, outputFileName);

    return 0;
}

