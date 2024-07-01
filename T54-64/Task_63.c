#include <stdio.h>

int main()
{
    int size = 0;
    printf("Please enter array size:");
    scanf("%d", &size);

    int array[size];
    printf("Please enter arrays elements:\n");
    for(int i = 0; i < size; i++)
    {   
       printf("Element %d: ", i + 1);
       scanf("%d", &array[i]);
    }
   
    int lenght = sizeof(array) / sizeof(array[0]);

    int number = 0;
    printf("Please enter searching number: ");
    scanf("%d", &number);
    
    int i = 0;
    while(i < lenght)
    {
        if(array[i] == number) {
          printf("YES\n");
         } else {
             printf("NO\n"); 
        }   
      i++;
   }

}
