#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main() {
    // Открытие файла и получение файлового дескриптора
    int fd = open("example.txt", O_RDONLY);
    
    if (fd == -1) {
        perror("open");
        return 1;
    }

    // Использование файлового дескриптора для чтения из файла
    char buffer[100];
    ssize_t bytesRead = read(fd, buffer, sizeof(buffer));

    if (bytesRead == -1) {
        perror("read");
        close(fd);
        return 1;
    }

    // Вывод прочитанных данных
    write(STDOUT_FILENO, buffer, bytesRead);

    // Закрытие файла
    close(fd);

    return 0;
}

