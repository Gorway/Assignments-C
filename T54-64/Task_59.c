#include <stdio.h>

int check(int*, int);

int main()
{
    int wrong[] = { 15,17,16,14,13 };
    int right[] = { 13,14,15,16,17 };

    int size = sizeof(wrong) / sizeof(wrong[0]);
    
    if(check(right, size))
    {
       printf("Elements of array are arranged in ascending order:\n");
    } else {
        printf("The Array elements are  not in ascending order:\n");

      }

    if(check(wrong, size))
    {
       printf("Elements of array are arranged in ascending order:\n");
    } else {
        printf("The Array elements are  not in ascending order:\n");

        }
}

int check(int arr[], int size)
{
    for(int i = 0; i < size -1; i++)
    {
        if(arr[i] > arr[i+1]) 
      {
        return 0;
      }
    }
   return 1;
}
