#include <stdio.h>
#include <stdlib.h>
#include <sys/sendfile.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
    int source_fd, dest_fd;
    struct stat stat_source;
    off_t offset = 0;

    // Открываем исходный файл для чтения
    source_fd = open("source.txt", O_RDONLY);
    if (source_fd == -1) {
        perror("Error opening source file");
        exit(EXIT_FAILURE);
    }

    // Определяем размер исходного файла
    fstat(source_fd, &stat_source);

    // Открываем файл назначения для записи
    dest_fd = open("destination.txt", O_WRONLY | O_CREAT, 0644);
    if (dest_fd == -1) {
        perror("Error opening destination file");
        exit(EXIT_FAILURE);
    }

    // Передаем содержимое исходного файла в файл назначения
    if (sendfile(dest_fd, source_fd, &offset, stat_source.st_size) == -1) {
        perror("Error sending file");
        exit(EXIT_FAILURE);
    }

    // Закрываем файлы
    close(source_fd);
    close(dest_fd);

    printf("File sent successfully.\n");

    return 0;
}

