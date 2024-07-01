#include <stdio.h>

int my_atoi(const char *str) {
    int result = 0;
    int sign = 1;  

    while (*str == ' ' || *str == '\t') {
        str++;
    }

    if (*str == '-') {
        sign = -1;
        str++;
    } else if (*str == '+') {
        str++;
    }

    while (*str >= '0' && *str <= '9') {
        result = result * 10 + (*str - '0');
        str++;
    }

    return result * sign;
}

int main() {
    const char *string = "123456789";  
                        
    int number = my_atoi(string); 

    printf("Result: %d\n", number);  
    
//    printf("Num / 2 = %d\n", number / 2);
    return 0;
}

