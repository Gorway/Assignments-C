#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define MAX_N 100

int isPrime(int n) {
    if(n <= 1) return 0;

    for(int i = 2; i * i <= n; i++) {
        if(n % i == 0) return 0;
    }

    return 1;
}

void* fill_array_with_primes(void* args);
void* print_array_and_free(void* args);

int main() {

    pthread_t thread1, thread2;
    int N;
    
    printf("Enter the number of prime numbers to generate (up to %d): ",MAX_N);
    scanf("%d", &N);

    if(N > MAX_N) {
        printf("Number too large. Maximum is %d\n", MAX_N);
        return 1;
    }

    pthread_create(&thread1, NULL, fill_array_with_primes, &N);
    int* primes_array;
    pthread_join(thread1, (void**)&primes_array);

    
    pthread_create(&thread2, NULL, print_array_and_free, primes_array);
    pthread_join(thread2, NULL);
    
    return 0;
}



void* fill_array_with_primes(void* args) {
    int N = *((int*)args);
    int* primes_array  = (int*)malloc(N * sizeof(int));
    if(primes_array == NULL) {
        printf("Memory allocation failed\n");
        pthread_exit(NULL);
    }

    int count = 0;
    for(int i = 2; i < N; ++i) {
        if(isPrime(i)) {
        primes_array[count++] = i;
        }
    }
    return primes_array;
}


void* print_array_and_free(void* args) {
    int* primes_array = (int*)args;
    printf("Prime numbers in the array:\n");
    for(int i = 0; primes_array[i] != 0; ++i) {
        printf("%d ", primes_array[i]);
    }
    printf("\n");
    free(primes_array);
    printf("Done\n");
    pthread_exit(NULL);
}
