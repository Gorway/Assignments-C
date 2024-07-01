#include <stdio.h>

#define CONCAT(x,y) x##y

int main() {

    printf("%d\n", CONCAT(12,34));
}

