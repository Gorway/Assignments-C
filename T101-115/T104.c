#include <stdio.h>
#include <stdlib.h>

int sumDiagonalElements(int** , int);

int main() {

    int size = 3;

    int** matrix = (int**)malloc(size * sizeof(int*));
        for(int i = 0; i < size; ++i)
        {
            matrix[i] = (int*)malloc(size * sizeof(int));
            }

        printf("Please enter enlement of matrix:\n");
        for(int i = 0; i < size; ++i) {
            for(int j = 0; j < size; ++j) {
                scanf("%d", &matrix[i][j]);
                }
        }
    int diagonalSum = sumDiagonalElements(matrix, size);
    printf("Sum of diagonal element is: %d\n", diagonalSum);

    for(int i = 0; i < size; ++i) {
        free(matrix[i]);
    }

    free(matrix);

    return 0;


}

int sumDiagonalElements(int** matrix, int size) {

    int sum = 0;

    for(int i = 0; i < size; ++i){
        sum += matrix[i][i];
    }

    return sum;
}
