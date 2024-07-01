#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>


void new_line_rm(char* str) {

    int sz = strlen(str);
    str[sz - 1] = (str[sz - 1] == '\n') ? '\0' : str[sz - 1];
}

void init_2d_str(char** arr_str, int count_1d, int size_1d) {
    for (int i = 0; i < count_1d; i++) {
        fgets(arr_str[i], size_1d, stdin);
        if (strlen(arr_str[i]) == size_1d - 1 && arr_str[i][size_1d - 2] != '\n') {
            while (getchar() != '\n'); // Очистка буфера ввода
        }
        new_line_rm(arr_str[i]);
    }
}

void show_2d_str(char** arr_str, int count_1d) {
    for (int i = 0; i < count_1d; i++) {
        if (arr_str[i] == NULL) {
            continue;
        }
        printf("%s\n", arr_str[i]);
    }
    printf("\n\n");
}

int digit_checker(char* str) {
    int i = 0;
    while (str[i] != '\0') {
        if (isdigit(str[i])) {
            return 0;
        }
        i++;
    }
    return 1;
}

int valid_str_counter(char** buff, int count_1d) {
    int count = 0;
    for (int i = 0, j = count_1d - 1; i <= j;) {
        if (!digit_checker(buff[i])) {
            char* tmp = buff[i];
            buff[i] = buff[j];
            buff[j] = tmp;
            j--;
        } else {
            count++;
            i++;
        }
    }
    return count;
}

int main() {
    int count_1d = 5; // Количество строк
    int size_1d = 10; // Размер каждой строки

    char* arr_str[count_1d];
    for (int i = 0; i < count_1d; i++) {
        arr_str[i] = (char*)malloc(size_1d * sizeof(char));
    }

    init_2d_str(arr_str, count_1d, size_1d);
    show_2d_str(arr_str, count_1d);

    int valid_count = valid_str_counter(arr_str, count_1d);

    printf("Количество строк без цифр: %d\n", valid_count);

    // Освобождение выделенной памяти
    for (int i = 0; i < count_1d; i++) {
        free(arr_str[i]);
    }

    return 0;
}

