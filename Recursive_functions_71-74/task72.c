#include <stdio.h>

void print_el(int *, int, int);

int main()
{
    int array[] = {10,20,30,40,50,60,70,80,100}; 
    int start = 0;
    int size = sizeof(array) / sizeof(array[0]);

    print_el(array, start, size);    
}

void print_el(int arr[], int start,  int size)
{
     if(start >= size) {
         return;
     }
      
      printf("%d ", arr[start]);
      print_el(arr, start + 1, size);
}
