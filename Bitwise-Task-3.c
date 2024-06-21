#include <stdio.h>

#define int_size sizeof(int) * 8

int main()
{
    int input = 0;

    printf("Enter number to count  0 and 1 bites: ");
    scanf("%d", &input);

    int ones = 0;
    int zeros = 0;

    int mask = 1;

    for(int i = 0; i < int_size; ++i) 
    {
        if(input & mask)
        {
           ones++;

        } else {

           zeros++;
        }

        input >>= mask;
    } 

    printf("In number: %d , ones: %d , zeros: %d\n", input, ones, zeros);
}
