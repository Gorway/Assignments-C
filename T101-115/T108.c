int swapDiagonals(int** matrix, int size) {

    for(int i = 0; i < size; ++i) {
        int temp = matrix[i][i];
        matrix[i][i] = matrix[i][size - 1 - i];
        matrix[i][size - 1 - i ] = temp;
    }
}
