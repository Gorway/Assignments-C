#include <stdio.h>

int main() {
    int n;

    for (n = 0; n < 10; n++) {
        printf("%d ", n);
        if (n == 5) {
            break; // Остановка выполнения цикла при достижении значения 5
        }
    }

    return 0;
}

