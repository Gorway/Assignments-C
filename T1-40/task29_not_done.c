#include <stdio.h>

int main()
{   
    int i = 0;
    int count = 0;
    char arr[] = "Hello";

    while (arr[i])
    {
        ++count;
        ++i;
    }
        
    printf("%d", arr[i]);    
    return 0;

}

