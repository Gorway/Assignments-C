#include <stdio.h>


int main()
{
    int year = 0;
     
    printf("Please enter the year: ");
    scanf("%d", &year);

    if ((year % 4 == 0 && year % 100 != 0) || ( year % 400 ==0)) {

        printf("The %d is Leap Year .\n", year);
    } else {
        printf("The %d is not Leap Year.\n", year);
    }

    return 0;
}
