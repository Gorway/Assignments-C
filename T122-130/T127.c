#include <stdio.h>

#define XNAME(n) x ## n
#define PRINT_XN(n) printf("x" #n " = %d\n", x ## n = 10);

int main() {

   int  XNAME(1);

    PRINT_XN(1);
}
