#include <stdio.h>


int main() 
{
    int hour = 0;
    int minute = 60;

    printf("Please enter hour` ");
    scanf("%d", &hour);

    minute *= hour;

    printf("The %d hour = %d minute\n", hour , minute);

    return 0;
}
