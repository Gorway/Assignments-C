#include <stdio.h>

void function( char operator, int num1, int num2);

int main() 
{
    int n1 = 0;
    int n2 = 0;
    char opcode = 0;

    printf("Welcom to simple calculator program:\n");
    printf("Please enter the operator('+', '-', '*', '/') :  Press 'Q' for exit: ");
    scanf(" %c", &opcode);
    printf("Please enter number 1:");
    scanf("%d", &n1);
    printf("Please enter number 2:");
    scanf("%d", &n2);
   
    function(opcode, n1, n2);

}

void function(char operator, int num1, int num2)

{
    while(operator != 'Q')
    {
        switch(operator) {
            case '+':
            printf("Result: %d\n", num1 + num2);
            break;
            case '-':
            printf("Result: %d\n", num1 - num2);
            break;
            case '*':
            printf("Result: %d\n", num1 * num2);
            break;
            case '/':
            if (num2 != 0) {
            printf("Result: %d\n", num1 / num2);
            } else {
                printf("Can not divide to zero\n");
            }
            break;
            case 'Q':
            break;

      }  
        printf("Please enter an arithmetic operation or 'Q' to quit the  program.\n");
        scanf(" %c", &operator);
     

  }
}


