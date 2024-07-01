#include <stdio.h>

void sort(int*, int );


int main()
{

   int array[] = { 15, 17, 16, 14, 13 };
   const int size = sizeof(array) / sizeof(array[0]);
   
   printf("Array before sorting: ");
   int i;
   for( i = 0; i < size; i++)
   {
       printf("%d ", array[i]);

    }
   printf("\n");
   
   sort(array, size);
}

void sort(int arr[], int size)
{
    int i = 0;
    int j = 0;
    int temp = 0;

    for(i = 0; i < size - 1; i++) 
    {
        for(j = 0; j < size -i -1; j++) 
        {
            if(arr[j] > arr[j + 1]) 
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

    printf("Array after sorting: ");
    
    for(i = 0; i < size; i++) 
        {
            printf(" %d", arr[i]);
            }
    printf("\n");
}
