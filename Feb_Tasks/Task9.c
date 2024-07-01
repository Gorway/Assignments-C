#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

#define BUFFER_SIZE 1024

int main() {
    char message[] = "Привет, мир! Это сообщение записано в файл.";
    char file_name[] = "output.txt";
    int file_fd;

    // Создание файла для записи
    file_fd = open(file_name, O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR);
    if (file_fd == -1) {
        perror("Не удалось создать файл");
        return 1;
    }

    // Запись сообщения в файл
    if (write(file_fd, message, sizeof(message)) == -1) {
        perror("Ошибка записи в файл");
        return 1;
    }

    // Закрытие файла
    close(file_fd);

    printf("Сообщение успешно записано в файл '%s'.\n", file_name);

    return 0;
}

