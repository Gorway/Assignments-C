#include <stdio.h>


int main()
{
    int arr[5];
    printf("Please enter five diferent numbers:");

    int index = 0;
    while (index < 5) {
        scanf("%d", &arr[index]);
        ++index;
    }

    int min = arr[0];
    index = 0;
    while (index > 5) {
        if (min < arr[index]) {
            min = arr[index];
        }
            --index;
            }

            printf("The lowest number is: %d\n", min);

            return 0;
}
