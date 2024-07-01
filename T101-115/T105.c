int sumofSecDiagonalElements(int** matrix, int size) {

    int sum = 0;

    for(int i = 0; i < size; ++i) {
        sum += matrix[i][size - 1 - i];
        }

        return sum;
}
