#include <stdio.h>

int Prime_function(int number) {
 
 if(number <= 1) {
        return 0;
    }

    for(int i = 2; i * i <= number; i++) {
        if(number % i == 0) {
            return 0;
        }
    }

    return 1;
}

typedef int(*Operation)(int);

void arrayChek(int *number, int size, Operation isPrime) {
    for(int i = 0; i < size; i++){
        if(isPrime(number[i])) {
            printf("%d is Prime\n", number[i]);
        } else {
            printf("%d is Composite\n", number[i]);
        }
    }
}

int main() 
{
    int numbers[] = {2,3,11,77,37,69,67,97,88};
  
    int size = sizeof(numbers) / sizeof(numbers[0]);   
    
    Operation isPrime = Prime_function; 

    arrayChek(numbers, size, isPrime);

    return 0;
}
