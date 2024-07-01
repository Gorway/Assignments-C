#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

#define SHM_SIZE 4096  // Размер shared memory

int main() {
    // Открываем существующий файл для чтения
    int fd = open("example.txt", O_RDONLY);
    if (fd == -1) {
        perror("open");
        exit(EXIT_FAILURE);
    }

    // Определяем размер файла
    struct stat st;
    fstat(fd, &st);
    off_t file_size = st.st_size;

    // Создаем shared memory
    key_t key = ftok(".", 'R');
    int shmid = shmget(key, file_size, IPC_CREAT | 0666);
    if (shmid == -1) {
        perror("shmget");
        exit(EXIT_FAILURE);
    }

    // Присоединяем shared memory к адресному пространству процесса
    char *shmaddr = shmat(shmid, NULL, 0);
    if ((void *)shmaddr == (void *)-1) {
        perror("shmat");
        exit(EXIT_FAILURE);
    }

    // Читаем содержимое файла и записываем в shared memory
    ssize_t bytes_read = read(fd, shmaddr, file_size);
    if (bytes_read == -1) {
        perror("read");
        exit(EXIT_FAILURE);
    }

    // Печатаем содержимое shared memory
    printf("Содержимое файла в shared memory:\n%s\n", shmaddr);

    // Отсоединяем shared memory от адресного пространства процесса
    if (shmdt(shmaddr) == -1) {
        perror("shmdt");
        exit(EXIT_FAILURE);
    }

    // Закрываем файл
    close(fd);

    return 0;
}

