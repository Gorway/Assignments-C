#include <stdio.h>

void stairs(int);


int main() 
{
    printf("Please enter string count: ");
    int n;
    scanf("%d", &n);
    
    stairs(n);
}


void stairs(int n)
{
    int end;
    int number = 0;
    if(end > n) {
        return;
    }

    printf("%d\n", number + 1);

    end++;
    number++;

    printf("%d %d\n",number, number);
    
    stairs(n)  ;
}




















/* 
int main()
{
    printf("Please enter strings count: ");
    
    int n;
    scanf("%d", &n);

    for(int i = 0; i < n; i++)
    {   
        if(i == 1) {

        printf("%d\n", i);

     } else  if(i == 2) {
           printf("%d%d\n", i,i);
     } else if(i == 3) {
            printf("%d%d%d\n", i,i,i);
     }
    }
}

*/
