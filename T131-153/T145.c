#include <stdio.h>
#include <unistd.h>

int main() {

    char *args[] = {"/bin/ps", "-ef", NULL};


    execv("/bin/ps", args);


    perror("execv");
    return 1;
}
