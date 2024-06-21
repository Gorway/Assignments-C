#include <stdio.h>

int main()
{
    int input = 0;

    printf("Enter number: ");
    scanf("%d", &input);

    int original_num = input;   

    int mask = 1;

    while(input & mask) {
        mask <<= 1;
    }

    input |= mask;

    printf("Iputed number %d\n", original_num);
    printf("Number with last met zero bit seted: %d\n", input);
}
