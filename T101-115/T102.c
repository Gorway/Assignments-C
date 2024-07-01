#include <stdio.h>
#include <stdlib.h>
#include <stdlib.h>

void show_1d_array(int* arr, int size) {
    for (int j = 0; j < size; j++) {
        printf("%d   ", arr[j]);
    }
    printf("\n");
}

void show_2d_array(int** mat, int row, int column) {
    for (int i = 0; i < row; i++) {
        show_1d_array(mat[i], column);
    }
    printf("\nEND SHOW \n");
}

void init_2d_array(int** mat, int row, int column) {
    for (int i = 0; i < row; i++) {
        if (rand() % 2 == 1) {
            for (int j = 0; j < column; j++) {
                mat[i][j] = rand() % 200;
            }
        } else {
            for (int j = 0; j < column; j++) {
                mat[i][j] = 1;
            }
        }
    }
}

int is_valid(int* arr, int size) {
    for (int i = 0; i < size; i++) {
        if (arr[i] != 1) {
            return 1;
        }
    }
    return 0;
}

void show_valid_arrays(int** mat, int row, int column) {
    for (int i = 0; i < row; i++) {
        if (is_valid(mat[i], column)) {
            show_1d_array(mat[i], column);
        }
    }
    printf("\nEND SHOW VALID ARRAYS\n");
}

void clear_buffer() {
    char ch = 0;
    while (ch != EOF && ch != '\n') {
        ch = getchar();
    }
}

void** create_2d_array(int count_1d, int count_elem, int size_elem) {
    void** tmp_ptr = (void**)calloc(count_1d, sizeof(void*));
    for (int i = 0; i < count_1d; i++) {
        tmp_ptr[i] = calloc(count_elem, size_elem);
        if (tmp_ptr[i] == NULL) {
            i--;
        }
    }
    return tmp_ptr;
}

void delete_2d_array(void** buff, int count_1d) {
    for (int i = 0; i < count_1d; i++) {
        if (buff[i] == NULL) {
            continue;
        }
        free(buff[i]);
    }
    free(buff);
}

int main() {
    int row = 5;    // Количество строк
    int column = 10; // Количество столбцов

    // Выделение памяти для двумерного массива целых чисел
    int** mat_int = (int**)create_2d_array(row, column, sizeof(int));

    // Инициализация и вывод двумерного массива целых чисел
    init_2d_array(mat_int, row, column);
    show_2d_array(mat_int, row, column);

    // Вывод строк, содержащих значения, отличные от 1
    show_valid_arrays(mat_int, row, column);

    // Освобождение памяти для двумерного массива целых чисел
    delete_2d_array((void**)mat_int, row);

    // Выделение памяти для двумерного массива типа double
    double** mat_double = (double**)create_2d_array(row, column, sizeof(double));

    // Инициализация и вывод двумерного массива типа double
    // (может быть изменено в соответствии с вашими потребностями)

    // Освобождение памяти для двумерного массива типа double
    delete_2d_array((void**)mat_double, row);

    return 0;
}

