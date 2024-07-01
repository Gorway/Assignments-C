#include <stdio.h>


int main ()
{
    int num1 = 0;
    int num2 = 0;
    char operator = '+';

    printf("Please enter an arithmetic operation or 'Q' to quit the program\n");


    printf("Enter the operator ` (+,-,*,/):");
    scanf(" %c", &operator);
    while(operator != 'Q') {
        printf("Please enter first number: ");
        scanf("%d", &num1);

        printf("Please enter second number: ");
        scanf("%d", &num2);

        switch (operator) {
        
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
        if (num2 !=0) {
            printf("Result:  %d\n", num1 / num2);
        
        } else { 
           
           printf("Can not divide to zero\n");
        }

        break;
        default:
            printf("Sorry, Wrong Action.\n");
    }
        printf("Please enter an arithmetic operation or 'Q' to quit the  program.\n");
        scanf(" %c", &operator);
}

        return 0;
} 

            
        
