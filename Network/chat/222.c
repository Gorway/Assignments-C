#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/mman.h>
#include <string.h>
#include <stdint.h>

#define CHUNK_SIZE 256

// Определение структуры Inode
typedef struct {
    size_t size;
    uint8_t i_type;
    uint8_t i_status;
    char i_name[CHUNK_SIZE];
} Inode;

// Определение значений
#define STATUS_PRIVATE 0
#define STATUS_PUBLIC 1
#define STATUS_FRIEND 2
#define FILE_INOD 1

int main() {
    int fd;
    Inode *ptr;
    Inode my_inode;

    // Открытие или создание файла base.atl
    fd = open("base.atl", O_CREAT | O_RDWR, 0666);
    if (fd == -1) {
        perror("Не удалось открыть файл");
        exit(EXIT_FAILURE);
    }

    // Получение размера структуры Inode
    size_t struct_size = sizeof(Inode);

    // Установка размера файла
    if (ftruncate(fd, struct_size) == -1) {
        perror("Не удалось установить размер файла");
        close(fd);
        exit(EXIT_FAILURE);
    }

    // Отображение файла в память с использованием mmap
    ptr = (Inode *) mmap(NULL, struct_size, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
    if (ptr == MAP_FAILED) {
        perror("Ошибка при выделении памяти");
        close(fd);
        exit(EXIT_FAILURE);
    }

    // Ввод значений от пользователя
    printf("Введите имя файла: ");
    scanf("%s", my_inode.i_name);
    printf("Введите размер файла: ");
    scanf("%zu", &my_inode.size);
    printf("Введите тип файла: ");
    scanf("%hhu", &my_inode.i_type);
    printf("Введите статус файла: ");
    scanf("%hhu", &my_inode.i_status);

    // Копирование данных в отображенную область памяти
    memcpy(ptr, &my_inode, struct_size);

    // Синхронизация изменений с диском
    if (msync(ptr, struct_size, MS_SYNC) == -1) {
        perror("Ошибка при синхронизации с диском");
        munmap(ptr, struct_size);
        close(fd);
        exit(EXIT_FAILURE);
    }

    // Отмена отображения файла в память и закрытие файла
    munmap(ptr, struct_size);
    close(fd);

    return 0;
}

