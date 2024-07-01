#include <stdio.h>


int main()
{
    int n = 0;

    printf("Enter the size of the array: ");
    scanf("%d", &n);

    char chars[n];
    
    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        scanf(" %c", &chars[i]);
    }

    printf("Array in revers order:\n");
    for (int i = n - 1; i >= 0; i--) {
        printf("%c ", chars[i]);
    }

    return 0;
}
