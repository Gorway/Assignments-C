#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>

#define FILENAME "example.txt"
#define TEXT "Hello, world!"

int main() {
    int fd = open(FILENAME, O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (fd == -1) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }
    
    if (write(fd, TEXT, sizeof(TEXT) - 1) == -1) {
        perror("Error writing to file");
        close(fd);
        exit(EXIT_FAILURE);
    }
    
    close(fd);

    pid_t pid = fork();
    if (pid == -1) {
        perror("fork");
        exit(EXIT_FAILURE);
    }

    if (pid == 0) { 
        execlp("./reader", "./reader", FILENAME, NULL);
    } else { 
     
        waitpid(pid, NULL, 0);
    }

    return 0;
}

