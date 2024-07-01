#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/mman.h>

#define SIZE 4096

int main() {
    void *address = (void *)0x10000000; // Указываем адрес для записи

    // Создаем анонимное отображение памяти по указанному адресу
    char *ptr = mmap(address, SIZE, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS | MAP_FIXED, -1, 0);
    if (ptr == MAP_FAILED) {
        perror("mmap");
        exit(EXIT_FAILURE);
    }

    // Записываем текст в отображенную память
    strcpy(ptr, "Hello, world!");

    // Проверяем, соответствует ли адрес записи указанному адресу
    if (ptr == address) {
        printf("Адрес записи соответствует указанному адресу.\n");
    } else {
        printf("Адрес записи НЕ соответствует указанному адресу.\n");
    }

    // Освобождаем отображение памяти
    if (munmap(ptr, SIZE) == -1) {
        perror("munmap");
        exit(EXIT_FAILURE);
    }

    return 0;
}

