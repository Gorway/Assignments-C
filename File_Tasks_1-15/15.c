#include <stdio.h>

int main() {
    FILE *file = fopen("fizz.txt", "r+");
    if (file == NULL) {
        perror("Error opening file");
        return 1;
    }

    // Перемещаем указатель в конец файла
    if (fseek(file, 0, SEEK_END) != 0) {
        perror("Error seeking to end of file");
        fclose(file);
        return 1;
    }

    // Записываем слово "линукс" в конец файла
    if (fprintf(file, "линукс\n") < 0) {
        perror("Error writing to file");
        fclose(file);
        return 1;
    }

    fclose(file);
    printf("Word 'линукс' added to the end of the file.\n");
    return 0;
}

