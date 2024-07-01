#include <stdio.h>
#include <setjmp.h>
#include <stdbool.h>

bool  print_array( int size) {
    if(size <= 0) 
        return false;
    
        return true;
 }

int main() {
    
    int arg;
    printf("Enter arg: ");
    scanf("%d", &arg);


    if(!print_array(arg)) {
        printf("Wrong size\n");
    } else { 
        printf("Correct size\n");
    }

}





    
