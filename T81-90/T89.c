#include <stdio.h>

typedef  int (*elementProd)(int);
void changedElements(int*, int, elementProd);

int mul(int element)
{
    return element * 2;
}

int main()
{
    int arr[] = {1,2,3,4,5,6};

    int size = sizeof(arr) / sizeof(arr[0]);

    printf("Array elements before function call: ");
    for(int i = 0; i < size; i++) {
        printf("%d%s", arr[i], (i < size - 1) ? ", ": ""); ; 
    }
  
    printf("\n");
  
  elementProd mulFunc  = mul;
   
  changedElements(arr,size , mulFunc);
   
   printf("Array elements after function call: ");
   for(int i = 0; i < size; i++) {
        printf("%d%s", arr[i], (i < size - 1) ? ", ": ""); ;
    }
    printf("\n");    
}



void changedElements(int *arr, int size, elementProd mul)
{
    for(int i = 0; i < size; i++){
        arr[i] = mul(arr[i]);
         
    }
}
