#include <stdio.h>
#define SIZE 10

int sum(int * ar, int n);

int main(){
    int marbels[SIZE] = {5,20,30,15,25,4,31,8,19,30};
    long answer = 0;
    answer = sum(marbels,SIZE);
    printf("Total sum of marbels arrays is %ld.\n", answer);
    printf("Total memory for marbels arrays is %lu.\n", sizeof(marbels));
    return 0;

}

int sum(int *ar, int n) {

    int i;
    int total = 0;

    for(i = 0; i < n; i++ )
{
    total += ar[i];
}
    printf("Size of variable ar is %zd.\n", sizeof(ar));

    return total;
}

















/*#include <stdio.h>
#define SIZE 10

int sum( int * arr, int len);

int main()
{
    int array[SIZE] = {1,2,3,4,5,6,7,8,9,10} ;
    int lenght = SIZE;
    int total = sum(array,lenght);
    printf("Total = %d\n", total);




}
int sum(int * arr, int len)
{
    int i = 0;
    int total = 0;
    for(i = 0; i < len; i++ ){
        total += arr[i];
        
    }
    return total;
}  
*/