#include <stdio.h>

int main()
{
    int input = 0;

    printf("Enter number to check is it odd or even: ");
    scanf("%d", &input);

    int mask = 1;

    if(input & mask)
    {
        printf("%d is odd!\n", input);

    } else {

        printf("%d is even!\n", input);
    }
}
