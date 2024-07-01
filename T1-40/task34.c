#include <stdio.h>


int main()
{
    int number;

    printf("Enter whole number bigger then 12:\n");
    scanf("%d", &number);

    if (number > 12) {
        printf("Reverse order of number:%d\n", number);
    
    while (number > 0) {
        int digit = number % 10;
        printf("%d", digit);
        number /=10;
    }

    return 0;
}
}
