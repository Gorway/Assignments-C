#include <stdio.h>

int *findmax(int arr[], int size);

int main()
{   
    printf("Enter array size: ");
    int size = 0;
    scanf("%d", &size);

    int arr[size];

    int i = 0;
    
    while(i < size) {
     printf(" Element %d:", i + 1);
     scanf("%d", &arr[i]);
     i++;
    }
    
   int *maxptr = findmax(arr, size);
   printf("Min value is: %i\n", *maxptr);
   return 0;
 }
 
int* findmax(int arr[], int size)
{
     int *max = &arr[0];
     for(int i = 1; i < size; i++) 
     {
         if (arr[i] > *max) // for min value (arr[i] < *max) 
         { 
            max = &arr[i];
         }
     }
     return max;
}

