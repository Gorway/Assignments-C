#include <stdio.h>

int main() {
    // Մուտքագրել թիվ
    int number;
    printf("Մուտքագրեք 12-ից մեծ ամբողջ թիվ: ");
    scanf("%d", &number);

    // Ստուգել որ թիվը մեծ է 12-ից
    if (number > 12) {
        // Կառուցել հակառակ հերթականությունը և տպել
        printf("Այդ թիվը հակառակ հերթականությամբ: ");
        while (number > 0) {
            printf("%d", number % 10);
            number /= 10;
        }
        printf("\n");
    } else {
        printf("Մուտքագրված թիվը չի մեծ է 12-ից։\n");
    }

    return 0;
}




