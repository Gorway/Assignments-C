#include <stdio.h>

int main() {
    int digits[4];
    int sum = 0;


    printf("Enter four number: ");
    for (int i = 0; i < 4; i++) {
        scanf("%1d", &digits[i]);
        sum += digits[i];
    }

  
    if (sum == 0) {
 
        int minDigit = digits[0];
        for (int i = 1; i < 4; i++) {
            if (digits[i] < minDigit) {
                minDigit = digits[i];
            }
        }
        printf("Smallest digit: %d\n", minDigit);
    } else {
        printf("Sum of digits is not ` 0.\n");
    }

    return 0;
}

