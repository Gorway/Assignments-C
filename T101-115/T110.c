
#include <stdio.h>
#include <stdlib.h>

int FindMin(int**, int, int);

int main() {

    int rows, cols;

    printf("Enter the number of rows and cols of the matrix (in NxM format): ");
    scanf("%dx%d", &rows, &cols);

    int** matrix = (int**)malloc(rows * sizeof(int*));
    for(int i = 0; i < rows; ++i) {
        matrix[i] = (int*)malloc(cols * sizeof(int));
    }

    printf("Enter elements of matrix:\n");

    for(int i = 0; i < rows; ++i) {
        for(int j = 0; j < cols; ++j) {
            scanf("%d", &matrix[i][j]);
        }
    }

    int minElement = FindMin(matrix, rows, cols);

    printf("Smallest element in matrix is: %d\n", minElement);

    for(int i = 0; i < rows; ++i) { 
        free(matrix[i]);
    }

    free(matrix);

    return 0;

}


int FindMin(int** matrix, int rows, int cols) {

    int minElement = matrix[0][0];
    
    for(int i = 0; i < rows; ++i) {
        for(int j = 0; j < cols; ++j) {
            if(matrix[i][j] < minElement) {
                minElement = matrix[i][j];
            }
        }
    }
    return minElement;
}


