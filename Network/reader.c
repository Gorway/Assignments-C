#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    int fd = open(argv[1], O_RDONLY);
    if (fd == -1) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    char buffer[BUFFER_SIZE];
    ssize_t bytes_read;

    printf("Contents of %s:\n", argv[1]);
    while ((bytes_read = read(fd, buffer, BUFFER_SIZE)) > 0) {
        if (write(STDOUT_FILENO, buffer, bytes_read) == -1) {
            perror("Error writing to stdout");
            close(fd);
            exit(EXIT_FAILURE);
        }
    }

    if (bytes_read == -1) {
        perror("Error reading from file");
        close(fd);
        exit(EXIT_FAILURE);
    }

    close(fd);

    return 0;
}

