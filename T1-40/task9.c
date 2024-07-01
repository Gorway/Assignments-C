#include <stdio.h>


int main()
{
    int bdate = 0;
    int year = 2023;

    printf("Please enter your year of birth`");
    scanf("%d", &bdate);

    int age = year - bdate;

    printf("You are %d years old\n", age);

    return 0;
}

