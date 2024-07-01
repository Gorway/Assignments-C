#include <stdio.h>
#include <stdlib.h>

int main() {
    char* env_valu = getenv("MY_VAR");
    
    printf("Enviroment value : %s \n", env_valu);
}
