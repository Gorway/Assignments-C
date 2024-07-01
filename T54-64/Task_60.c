#include <stdio.h>

int find_max(int*, int);

int main()
{
    int arr[] = { 10,9,11,8,12,6,5,15,4 };
    int size = sizeof(arr) / sizeof(arr[0]);
    
    int secmax = find_max(arr,size);

    printf("Second max element in array is` %d\n", secmax);

    return 0;

}


int find_max(int arr[], int size)
{ 
    int max = arr[0];
    int second_max = arr[1];

    for(int i = 2; i < size ; i++)
    {
        if(arr[i] > max) {
            second_max = max;
            max = arr[i];
        } else if (arr[i] > second_max && arr[i] != max) {
            second_max = arr[i];
        }

    }

     return second_max;
}
