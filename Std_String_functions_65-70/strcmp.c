#include <stdio.h>


int strcmp_(const char*, const char*);

int main()
{
    const char string1[] = "Bye, World";
    const char string2[] = "Hallo, World";
    
    int result = strcmp_(string1, string2);

    if (result < 0) {
        printf("%d\n",result); // ete str1 < str2
    } else if (result > 0) {
        printf("%d\n", result);// ete str1 > str2
    } else {
        printf("%d\n", result); // ete str1 == str2
    }

    return 0;
}
     

int strcmp_(const char str1[], const char str2[]) 
{

    while (*str1 != '\0' && *str2 != '\0' && *str1 == *str2) {
        str1++;
        str2++;
    }

    return *str1 - *str2;
}
