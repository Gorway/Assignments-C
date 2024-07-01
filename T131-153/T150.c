#include <unistd.h>
#include <stdio.h>

int main() {

     char *chromePath = "/usr/bin/google-chrome";  

    
    char *args[] = {chromePath, "https://www.google.com", NULL};

   
    if (execv(chromePath, args) == -1) {
  
        printf("Error opening Google Chrome");
        return 1;
    }

    return 0;
}

