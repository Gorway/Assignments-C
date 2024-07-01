#include <stdio.h>
#include <string.h>

void lenght(char arr[]);
void firstOindex(char arr[]);
void l_to_z(char arr[], int size);
void uppercase(char arr[]);
void isPolindrome(char arr[], int size);
void space_count(char arr[]);
void lastOindex(char arr[]); 

int main()
{
    char text[] = "Hello, World";
    int size = sizeof(text) / sizeof(text[0]);

    printf("%s\n", text);

    lenght(text);
    firstOindex(text);
    l_to_z(text, size);
    uppercase(text);
    isPolindrome(text, size);
    space_count(text);
    lastOindex(text);
}

void lenght(char arr[]) //Function: 1
{
    int lenght = 0; 

    for(int i = 0; arr[i] != 0; i++)
    {
        lenght ++;
    }
    printf("Lenght is: %d\n", lenght);
}

void firstOindex(char arr[]) // Function: 2
{
    int index = 0;
    for(int i = 0; arr[i] != '\0'; i++)
    {
        if(arr[i] == 'o')
        {
            index = i;
            break;
        }
 
    }
 printf("First index of` 'o'  is : %d\n", index);
}

void l_to_z( char arr[], int size) // Function: 3
{
    char copy[size];
    strcpy(copy, arr);

    for(int i = 0; copy[i] != '\0'; i++)
        {
            if(copy[i] == 'l')
            {
               copy[i] = 'z';
                
            }
        }
   printf("%s\n", copy);
}

void uppercase(char arr[]) // Function: 4
{
    for(int i = 0; arr[i] != '\0'; i++)
    {
        if(arr[i] >= 'a' && arr[i] <= 'z')
        {
            arr[i] -= 32;
        }

    }
    printf("%s\n", arr);
}

void isPolindrome(char arr[], int size) // Functoin: 5
{
    int isPalindrome = 1;
    for(int i = 0; i < size / 2; ++i)
    {
        if(arr[i] != arr[size - i - 1]) {
            isPalindrome = 0;
            break;
        }
    }

    if(isPalindrome) {
        printf("String is Palnindrome.\n");
    } else {
        printf("String is not Palindrome.\n");
    }
}

void space_count(char arr[]) // Function :6
{
  int spacecount = 0;
    
    for(int i = 0; arr[i] != '\0'; i++)
        {
            if(arr[i] == ' ') {
                ++spacecount;
            }
        }
        printf("Spaces count is: %d\n", spacecount);
}


void lastOindex(char arr[]) // Function: 7
{
    int index = 0;

    for(int i = 0; arr[i] != '\0'; ++i)    {
        if(arr[i] == 'o' || arr[i] == 'O' ) {
            index = i;
        }
 
    }
  printf("Last index of` 'o'  is : %d\n", index);
}
