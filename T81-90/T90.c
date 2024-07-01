#include <stdio.h>

int isValidURL(char*);


int strcmp_(const char str1[], const char str2[], size_t n) 
 {
 
     while (n > 0 && *str1 && *str2) {
        if(*str1 != *str2) {
         return (*str1  - *str2);
     }
 
      str1++;
      str2++;
      n--;
     }

      if( n > 0) {
          return (*str1 -*str2);
          }
     return 0;
 }

       
int main() 
{
    char url[100];
    printf("Enter URL : ");
    scanf("%s", url);

    if(isValidURL(url)) {
        printf("URL is Valid:\n");
    } else {
        printf("Sorry, URL is not Valid:\n");
    }

}

int  isValidURL( char* str)
{
    if(strcmp_(str, "https://", 8) == 0) {
        return 1;
    }
    return 0;
}
