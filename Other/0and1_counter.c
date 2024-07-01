#include <stdio.h>

int main() {
    // Ներմուծեք թիվ
    printf("Մուտքագրեք թիվ: ");
    int number;
    scanf("%d", &number);

    // Հաշվեք 0-ների և 1-երի քանակները
    int countZeros = 0, countOnes = 0;
    while (number > 0) {
        if (number % 2 == 0) {
            countZeros++;
        } else {
            countOnes++;
        }
        number /= 2;
    }

    // Տպեք արդյունքը
    printf("0-ների քանակը: %d\n", countZeros);
    printf("1-երի քանակը: %d\n", countOnes);

    return 0;
}
