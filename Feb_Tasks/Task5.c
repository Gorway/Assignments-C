#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

#define BUFFER_SIZE 25

int main() {
    char write_msg[BUFFER_SIZE] = "Hello, this is a message!";
    char read_msg[BUFFER_SIZE];
    int fd[2];

    // создание pipe
    if (pipe(fd) == -1) {
        fprintf(stderr, "Pipe failed");
        return 1;
    }

    // открытие файла для записи
    int file_fd = open("output.txt", O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR);
    if (file_fd == -1) {
        fprintf(stderr, "Failed to open file");
        return 1;
    }

    // запись сообщения в pipe
    write(fd[1], write_msg, BUFFER_SIZE);

    // чтение сообщения из pipe и запись в файл
    ssize_t bytes_read = read(fd[0], read_msg, BUFFER_SIZE);
    if (bytes_read > 0) {
        write(file_fd, read_msg, bytes_read);
    }

    // закрытие файловых дескрипторов
    close(fd[0]);
    close(fd[1]);
    close(file_fd);

    return 0;
}

