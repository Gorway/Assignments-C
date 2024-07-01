#include <stdio.h>
#include <signal.h>
#include <string.h>

int main() {
    int i;

    for (i = 1; i < NSIG; i++) {
        printf("Сигнал %d: %s\n", i, strsignal(i));
    }

    return 0;
}

