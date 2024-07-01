#include <stdio.h>

int isPrime(int num) {
    for(int i = 2; i * i <= num; i++) {
        if(num % i == 0) {
            return 0;
        }
    }
        return 1;
}

int main() {

    FILE* file = fopen("task2.txt", "w+");

    int num = 15;

    for(int i = 0; i < num; i++) {
        if(isPrime(i)) {
            fprintf(file, "%d ", i);
        }
    }

    fclose(file);
}
