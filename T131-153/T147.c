#include <stdio.h>
#include <stdlib.h>

int main() {

    char* envirm = getenv("MY_VAR");

    printf("%s\n", envirm);
}
