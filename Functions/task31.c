#include <stdio.h>

void function(char msg[] , int size);

int main()
{
    char text[] = "Hello, World";
    int size = sizeof(text)/ sizeof(text[0]);
    function(text,size);   

}

void function(char msg[],int size ) 
{
    for(int i = 0; i < size; i++) {
        if (msg[i] >= 'a' && msg[i] <= 'z') {
           
           msg[i] -= 32;
      } 

    }
    printf("%s\n", msg);
}
