#include <stdio.h>
#include <pthread.h>

#define NUM_THREADS 4

typedef struct {
    int operand1;
    int operand2;
    char operator;
    int result;
} Operation;

void *perform_operation(void *arg) {
    Operation *operation = (Operation *)arg;

    switch (operation->operator) {
        case '+':
            operation->result = operation->operand1 + operation->operand2;
            break;
        case '-':
            operation->result = operation->operand1 - operation->operand2;
            break;
        case '*':
            operation->result = operation->operand1 * operation->operand2;
            break;
        case '/':
            if (operation->operand2 != 0)
                operation->result = operation->operand1 / operation->operand2;
            else
                operation->result = 0;
            break;
        default:
            operation->result = 0; 
            break;
    }

    pthread_exit(NULL);
}

int main() {
    pthread_t threads[NUM_THREADS];
    Operation operations[NUM_THREADS];

    
    operations[0].operand1 = 10;
    operations[0].operand2 = 5;
    operations[0].operator = '+';

    operations[1].operand1 = 20;
    operations[1].operand2 = 8;
    operations[1].operator = '-';

    operations[2].operand1 = 6;
    operations[2].operand2 = 3;
    operations[2].operator = '*';

    operations[3].operand1 = 24;
    operations[3].operand2 = 6;
    operations[3].operator = '/';

   
    for (int i = 0; i < NUM_THREADS; ++i) {
        pthread_create(&threads[i], NULL, perform_operation, (void *)&operations[i]);
    }

  
    for (int i = 0; i < NUM_THREADS; ++i) {
        pthread_join(threads[i], NULL);
    }

 
    for (int i = 0; i < NUM_THREADS; ++i) {
        printf("Result of operation %d: %d\n", i + 1, operations[i].result);
    }

    return 0;
}

