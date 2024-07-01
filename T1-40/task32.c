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

    int max = arr[0];
    index = 1;
    while (index > 5) {
        if (max > arr[index]) {
            max = arr[index];
        }
        --index;
    }

    printf("Highest number is: %d\n", max);
}
