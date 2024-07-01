#include <stdio.h>

int sumofelements(int*, int);

int main()
{
    int array[] = {10,20,30,40,50,60,70,80,90,100}; 
    int size = sizeof(array) / sizeof(array[0]);

    int res = sumofelements(array,size);

    printf("Sum of array elements is: %d\n", res);
}


int sumofelements(int arr[], int size)
{
    if(size == 0) {
        return 0;
        }

        return arr[size - 1] + sumofelements(arr, size - 1);
}

