#include <stdio.h>

void swap(int* , int*);

int main()
{
    int number1 = 10;
    int number2 = 5;
    
    printf("Before swap: Number1 = %d, Number2 = %d\n", number1, number2);
    swap(&number1, &number2);
    printf("After swap: Number1 = %d, Number2 = %d\n", number1, number2);

    return 0;

}
 
void swap(int* number1, int* number2)
{
    int temp = *number1;
    *number1 = *number2;
    *number2 = temp;
}
