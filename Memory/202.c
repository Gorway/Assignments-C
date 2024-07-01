#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/mman.h>

void *my_mremap(void *old_address, size_t old_size, size_t new_size) {
    void *new_address;

    // Создаем новое отображение памяти
    new_address = mmap(NULL, new_size, PROT_READ | PROT_WRITE,
                       MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);
    if (new_address == MAP_FAILED) {
        perror("mmap");
        return NULL;
    }

    // Копируем данные из старого отображения в новое
    if (old_address != NULL) {
        if (old_size > new_size)
            old_size = new_size;

        memcpy(new_address, old_address, old_size);

        // Освобождаем старое отображение памяти
        if (munmap(old_address, old_size) == -1) {
            perror("munmap");
            // При возникновении ошибки освобождаем новое отображение
            munmap(new_address, new_size);
            return NULL;
        }
    }

    return new_address;
}

int main() {
    size_t old_size = 4096;
    size_t new_size = 8192;

    // Создаем старое отображение памяти
    void *old_mapping = mmap(NULL, old_size, PROT_READ | PROT_WRITE,
                             MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);
    if (old_mapping == MAP_FAILED) {
        perror("mmap");
        exit(EXIT_FAILURE);
    }

    printf("Успешно создано отображение памяти размером %zu байт\n", old_size);

    // Изменяем размер отображения памяти
    void *new_mapping = my_mremap(old_mapping, old_size, new_size);
    if (new_mapping == NULL) {
        perror("my_mremap");
        munmap(old_mapping, old_size);
        exit(EXIT_FAILURE);
    }

    printf("Успешно изменен размер отображения памяти с %zu на %zu байт\n", old_size, new_size);

    // Освобождаем память
    munmap(new_mapping, new_size);

    return 0;
}

