#include <stdio.h>

int add(int, int);
int sub(int,int);

int caller (int (*Operation) (int,int) , int, int);


int main()
{
    int x = 10;
    int y = 5;
    int result = 0;

    result = caller(add, x, y);
    printf("Result of add = %d\n", result );

    result = caller(sub, x, y);
    printf("Result of sub = %d\n", result );

    
}


int add(int x , int y)
{
    return x + y;
}

int sub(int x , int y)
{
    return x - y;
}

int caller(int (*operation)(int,int) , int x , int y)
{
    return (*operation) (x,y);
}





/*  

int bounce(int a);
int caller (int(*function) (int), int b);

int main() 
{
    int num;
    int (*fptr) (int) = bounce;
   
   num = (*fptr)(10);
    printf("Returned Value: %d\n", num);

   num = caller(fptr,5);
   printf("Returned Value: %d\n", num);

   return 0;
}

int bounce(int a)
{
    printf("\ Recived Value: %d\n", a);
    return((3 * a) + 3);

}

int caller(int (*function) (int), int b)
{
    (*function) (b);
}

*/
