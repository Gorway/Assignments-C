#include <stdio.h>

void smallestsymb(char arr[], int size);
void biggestsymb(char arr[], int size);
void vowels(char arr[], int size);
void reverse(char arr[], int size);
void uppercase(char arr[], int size);

int main() {

    char arr[] = "CheeseBurger";
    int size = sizeof(arr) / sizeof(arr[0]);
    printf("%s\n", arr);
    smallestsymb(arr, size);
    biggestsymb(arr, size);
    vowels(arr,size); 
    reverse(arr,size);
    uppercase(arr,size);

 return 0;
       
}

void smallestsymb(char arr[], int  size) //Function: 1
{
    int smallestSymbol = arr[0];

    for(int i = 1; arr[i] != '\0';  i++)
    {
        if(arr[i] < smallestSymbol)
        {
            smallestSymbol = arr[i];            
        }         
    }
  
    printf("The smallest ASCII symbol is ` %c\n", smallestSymbol);    
}


void biggestsymb(char arr[], int size) // Function: 2
{
    int biggestsymbol = arr[0];

    for(int i = 1; arr[i] != '\0'; ++i) 
    {
        if(arr[i] > biggestsymbol) 
        {
            biggestsymbol = arr[i];             
        }       
     } 


     printf("The biggest ASCII symbol is ` %c\n", biggestsymbol);  
}

void vowels(char arr[], int size) // Function: 3
{
    char vowels[size];
    printf("All vowels in string` ");    
    
    for(int i = 0; arr[i] != '\0'; i++)
    {
        if(arr[i] == 'i' || arr[i] == 'u' || arr[i] == 'o' || arr[i] == 'a' ||
            arr[i] == 'e') {    
          printf("%c " , arr[i] );       
       }            
    }
   printf("\n");    
   // vowels[size - 1] = '\0';
   // printf("The vowels is` %s\n", vowels);
   }


void reverse(char arr[], int size)
{
   printf("Reversed string: ");
   for(int i = size -1; i >= 0; i--){
      
     // reverse_arr[lenght] = '\0';
      printf("%c", arr[i]);

    }
    printf("\n");
}

void uppercase(char arr[], int size)
{
    printf("Uppercase string: ");
    for(int i = 0; arr[i] != '\0'; i++) 
        {
            if (arr[i] >= 'a' && arr[i] <= 'z')
            {
                arr[i] -= 32;
            }
            printf("%c",arr[i]);
        }
        printf("\n");
}
