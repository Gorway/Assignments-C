#include <stdio.h>

void function(int*, int);

int main()
{
    int size = 0 ;
    printf("Please enter array size:");
    scanf("%d", &size);

    int array[size];

    printf("Please enter arrays elements:\n");
    for(int i = 0; i < size; i++)
    {
        printf("Element%d: ", i + 1);
        scanf("%d", &array[i]);
    }

    int lenght = sizeof(array) / sizeof(array[0]);
    
    function(array,size);

    printf("Elements divided by elements count: ");
    for(int i = 0; i < size; i++)
        {
            printf("%d ", array[i]);
        }
    printf("\n");
}    


void function(int arr[], int size)
{
    

   for(int i = 0; i < size ; i++)
    {   
         arr[i] /= size;
    }
}

