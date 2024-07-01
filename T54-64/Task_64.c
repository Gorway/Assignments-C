#include <stdio.h>

int main()
{
    int numbers[]   = {1,2,3,4,5,6,7,8,9,10}; 
    int numbers2[]  = {10,9,8,7,6,5,4,3,2,1};
    

    int size = sizeof(numbers) / sizeof(numbers[0]);

    for(int i = 0; i < size; i++)
    {
       if(numbers[i] == numbers2[i])
            {
                printf("Arrays elements are equal: \n");
            } else {
                printf("Arrays elements are not equal:\n");
            }
        } 
    
}
