int SumBelowMainDiagonal(int** matrix, int size) {

    int sum = 0;

    for(int i = 0; i < size; ++i) {
        for(int j = i + 1; j < size; ++j) {
            sum += matrix[i][j];
        }
    }

    return sum;
}
