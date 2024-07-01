#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <ctype.h>

#define BUFFER_SIZE 1024

int main() {
    int fd[2];
    char input_buffer[BUFFER_SIZE];
    char output_buffer[BUFFER_SIZE];

    // Создание pipe
    if (pipe(fd) == -1) {
        perror("Pipe failed");
        return 1;
    }

    // Запрос текста у пользователя
    printf("Введите текст: ");
    fgets(input_buffer, BUFFER_SIZE, stdin);

    // Преобразование текста в верхний регистр
    for (int i = 0; input_buffer[i] != '\0'; i++) {
        output_buffer[i] = toupper(input_buffer[i]);
    }

    // Запись преобразованного текста в pipe
    write(fd[1], output_buffer, strlen(output_buffer) + 1);

    // Чтение из pipe и вывод на экран
    read(fd[0], input_buffer, BUFFER_SIZE);
    printf("Преобразованный текст: %s\n", input_buffer);

    // Закрытие pipe
    close(fd[0]);
    close(fd[1]);

    return 0;
}

