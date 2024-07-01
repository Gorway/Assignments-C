#include <stdio.h>

int main ()
{
    int x = 0;
    
    printf("Enter any number`");
    scanf("%d", &x);

    int result = 4 * x + 21 * x * x -12;

    printf("Result = %d\n",result);

    return 0;
}
