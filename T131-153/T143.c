#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

void print_main_diagonal(int** matrix, int rows, int cols ) {
    
    printf("Main Diagonal Elements:\n");
    for(int i = 0; i < rows; i++) {
        printf("%d ", matrix[i][i]);
    }

    printf("\n");
}
 
int Rec_factorial( int num ) {

    if(num == 0 || num == 1) {
        return 1;
    } else {
        return num * Rec_factorial( num - 1 );
    }
}

int main() {

    pid_t pid1;
    pid_t pid2;
    
    int num = 5;

    if((pid1= fork()) == 0 ) {

        printf("Childe 1 PID: %d\n", getpid());
        
        int rows = 3;
        int cols = 3;

        int num = 3;
        
        int ** matrix = (int**)malloc(rows * sizeof(int));
        for(int i = 0; i < rows; i++) {
            matrix[i] = (int*)malloc(cols * sizeof(int));
        }

        for(int i = 0; i < rows; i++) {
            for(int j = 0; j < cols; j++) {
                matrix[i][j] = rows * num;
            }
        }

        print_main_diagonal(matrix, rows, cols);

        for(int i = 0; i < rows; i++) {
            free(matrix[i]);
        }
        free(matrix);
        
        exit(0);
    }  else {

        if((pid2 = fork()) == 0) {

            printf("Childe 2 PID: %d\n", getpid());

            int num = 5;

            printf("!%d = %d\n", num, Rec_factorial(num));

            exit(0);
        }  else {

            printf("Parent PID: %d\n", getpid());

            waitpid(pid1, NULL, 0);
            waitpid(pid2, NULL, 0);
        
        printf("Parent process has finished waiting\n");
        }
    }

    return 0;
 }
    

