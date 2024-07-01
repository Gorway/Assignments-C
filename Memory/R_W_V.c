
#include <stdio.h>
#include <stdlib.h>
#include <sys/uio.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

int main() {
    // Создаем две области памяти для чтения/записи
    char buf1[6];
    char buf2[6];

    // Заполняем данные в первой области памяти
    sprintf(buf1, "Hello");
    sprintf(buf2, "World");
    
    // Определяем структуры iovec для чтения/записи
    struct iovec iov[2];
    iov[0].iov_base = buf1;
    iov[0].iov_len = 6;  // Размер данных в buf1
    iov[1].iov_base = buf2;
    iov[1].iov_len = 6;  // Размер данных в buf2

    // Записываем данные из нескольких областей памяти в файл
    int fd = open("output.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (fd == -1) {
        perror("open");
        exit(1);
    }

    ssize_t bytes_written = writev(fd, iov, 2);
    if (bytes_written == -1) {
        perror("writev");
        exit(1);
    }

    printf("Записано %zd байт в файл.\n", bytes_written);

    // Читаем данные из файла в несколько областей памяти
    char buf3[6];
    char buf4[6];

    struct iovec iov_read[2];
    iov_read[0].iov_base = buf3;
    iov_read[0].iov_len = 6;
    iov_read[1].iov_base = buf4;
    iov_read[1].iov_len = 6;

    // Открываем файл для чтения
    fd = open("output.txt", O_RDONLY);
