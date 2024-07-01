#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/wait.h>


int main() {
    
    char* args[] = {"bin/ls" "-l", NULL};
    

        execv("/bin/ls", args);

        perror("execl"); 

    return 0;
}
