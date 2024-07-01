int*  MatrixMaxValues(int** matrix, int rows, int cols) {

    int* maxValues = (int*)malloc(rows * sizeof(int));

    if(maxValues == NULL) {
        printf("Memory Allocation Failed\n");
        exit(1)
        }

        for(int i = 0; i < rows; ++i) {
            int max = matrix[i][0];
            for(int j = 1; j < cols; ++j) {
                if(matrix[i][j] > max) {
                    max = matrix[i][j];
                }
            }

            maxValues[i] = max;
        }

        return maxValues;
}
