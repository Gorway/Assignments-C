#include <stdio.h>

int  diff_counter(char*);

int main()
{

    char array[] = "Hello, World";
    
    int size = sizeof(array) / sizeof(array[0]);

    int difference = diff_counter(array);
   
    printf("There is %d difference in string.\n", difference);

    return 0;
}

int diff_counter(char array[])
{
    int diff_count = 0;
    int repetive = 0;
    int unique = 0;

    for(int i = 0; array[i] != '\0' && array[i+1] != '\0'; i++)
    { 
        if(array[i] == array[i + 1])
        {
             repetive += 1;
        } 
         if (array[i] != array[i+1]) 
        {
             unique += 1;
        }
    } 
         
    
   return diff_count = unique - repetive;
}
