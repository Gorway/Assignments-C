#include <stdio.h>


int main () 
{
    int age = 0;
    int days = 365;

    printf("Pleas enter your age `");
    scanf("%d", &age );

    days *= age;

    printf("Your age in days = %d\n", days);

    return 0;
}
