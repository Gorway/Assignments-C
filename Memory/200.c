#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <unistd.h>
#include <fcntl.h>

#define SHM_SIZE 1024  // Размер shared memory
#define MAX_PERFECT_NUMBERS 5  // Максимальное количество идеальных чисел
#define FILENAME "perfect_numbers.txt"  // Имя файла для записи

// Функция для проверки идеального числа
int isPerfectNumber(int n) {
    int sum = 1; // Инициализируем сумму как 1, потому что 1 всегда является делителем

    // Проверяем делители числа до его корня
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            sum += i;
            if (i != n / i) {
                sum += n / i;
            }
        }
    }

    // Если сумма делителей равна числу, то число является идеальным
    return sum == n;
}

int main() {
    key_t key = ftok(".", 'R'); // Генерируем ключ для shared memory

    int shmid = shmget(key, SHM_SIZE, IPC_CREAT | 0666); // Создаем shared memory
    if (shmid == -1) {
        perror("shmget");
        exit(1);
    }

    int *shmaddr = (int *)shmat(shmid, NULL, 0); // Присоединяем shared memory к адресному пространству процесса
    if ((void *)shmaddr == (void *)-1) {
        perror("shmat");
        exit(1);
    }

    // Открываем файл для записи
    int fd = open(FILENAME, O_WRONLY | O_CREAT | O_TRUNC, 0666);
    if (fd == -1) {
        perror("open");
        exit(1);
    }

    // Записываем идеальные числа из shared memory в файл
    for (int i = 0; i < MAX_PERFECT_NUMBERS; i++) {
        dprintf(fd, "%d ", shmaddr[i]);
    }
    dprintf(fd, "\n");

    // Закрываем файл
    close(fd);

    // Отсоединяем shared memory от адресного пространства процесса
    if (shmdt((void *)shmaddr) == -1) {
        perror("shmdt");
        exit(1);
    }

    return 0;
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/ipc.h>
#include <sys/shm.h>

// Функция для проверки числа на идеальность
int is_perfect(int num) {
    int sum = 1;
    for (int i = 2; i * i <= num; ++i) {
        if (num % i == 0) {
            sum += i;
            if (i * i != num) {
                sum += num / i;
            }
        }
    }
    return sum == num && num != 1;
}

int main() {
    key_t key = ftok("shmfile",65); // Генерируем ключ для shared memory
    int shmid = shmget(key, 1024, 0666|IPC_CREAT); // Создаем shared memory
    int *shmaddr = (int*) shmat(shmid,(void*)0,0); // Присоединяемся к shared memory

    // Записываем идеальные числа в shared memory
    int count = 0;
    for (int i = 1; count < 10; ++i) {
        if (is_perfect(i)) {
            shmaddr[count++] = i;
        }
    }

    // Отсоединяемся от shared memory
    shmdt(shmaddr);

    // Открываем файл для записи
    FILE *file = fopen("output.txt", "w");
    if (file == NULL) {
        perror("Ошибка открытия файла");
        return 1;
    }

    // Записываем содержимое shared memory в файл
    for (int i = 0; i < 10; ++i) {
        fprintf(file, "%d\n", shmaddr[i]);
    }

    // Закрываем файл
    fclose(file);

    return 0;
}

