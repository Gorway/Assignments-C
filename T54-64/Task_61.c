#include <stdio.h>

void reverse(char*, int);

int main()
{
    char array[] = "Hello, World";
    
    int  size = 0;
    for(int i = 0; array[i] != '\0'; i++)
    {
        size++;
    }
    
    printf("Array befor reverse: %s\n", array);
    reverse(array, size);

    printf("Reverse Array: %s\n", array);

}

void reverse(char arr[], int size)
{   
    int start = 0;
    int end = size - 1;

    while(start < end) {
        char temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;

        start++;
        end--;
    }
}
