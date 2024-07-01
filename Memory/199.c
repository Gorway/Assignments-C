#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

#define SHM_SIZE 1024  // Размер shared memory

int main() {
    key_t key = ftok(".", 'R'); // Генерируем ключ для shared memory

    int shmid = shmget(key, SHM_SIZE, IPC_CREAT | 0666); // Создаем shared memory
    if (shmid == -1) {
        perror("shmget");
        exit(1);
    }

    char *shmaddr = shmat(shmid, NULL, 0); // Присоединяем shared memory к адресному пространству процесса
    if (shmaddr == (char *)-1) {
        perror("shmat");
        exit(1);
    }

    char filename[] = "example.txt";

    // Открываем файл для чтения и записи
    int fd = open(filename, O_RDWR);
    if (fd == -1) {
        perror("open");
        exit(1);
    }

    struct stat st;
    fstat(fd, &st);
    int filesize = st.st_size;


    // Записываем содержимое shared memory в начало файла
    lseek(fd, 0, SEEK_SET);
    write(fd, shmaddr, filesize + strlen(new_line));

    close(fd);

    // Отсоединяем shared memory от адресного пространства процесса
    shmdt(shmaddr);

    return 0;
}

