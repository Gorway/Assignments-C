#include <stdio.h>

typedef int (*Transformfnc)(char);

 void replace(char symbols[], Transformfnc transform) {
    
    printf("Symbols ASCII Values: ");
     for (int i = 0; symbols[i] != '\0'; i++) {
       printf("%d ", symbols[i]  transform(symbols[i]));
    }
    printf("\n");    
}


int charToAscii(char c) {
    
    return (int)c ;
}

int main() {

    char myString[] = "Hello World!";

    printf("String: %s\n", myString);

    replace(myString, charToAscii);
   
    
    return 0;
}

