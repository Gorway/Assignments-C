#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#define MAX_SIZE 1024

int main() {
    int shmid;
    key_t key;
    char input[MAX_SIZE];

    // Создание межпроцессного ключа с помощью функции ftok()
    if ((key = ftok("file.txt", 'A')) == -1) {
        perror("ftok");
        exit(1);
    }

    // Создание или получение разделяемой памяти
    if ((shmid = shmget(key, MAX_SIZE, IPC_CREAT | IPC_EXCL | 0666)) < 0) {
        perror("shmget");
        exit(1);
    }

    // Подключение разделяемой памяти
    char *shm;
    if ((shm = shmat(shmid, NULL, 0)) == (char *) -1) {
        perror("shmat");
        exit(1);
    }

    printf("Введите текст для записи в разделяемую память:\n");
    fgets(input, MAX_SIZE, stdin);

    // Проверка размера введенного текста
    int inputLength = strlen(input);
    if (inputLength >= MAX_SIZE) {
        // Увеличение размера разделяемой памяти
        if (shmctl(shmid, IPC_RMID, NULL) == -1) {
            perror("shmctl");
            exit(1);
        }

        shmid = shmget(key, inputLength + 1, IPC_CREAT | 0666);
        if (shmid < 0) {
            perror("shmget");
            exit(1);
        }

        // Подключение разделяемой памяти
        if ((shm = shmat(shmid, NULL, 0)) == (char *) -1) {
            perror("shmat");
            exit(1);
        }
    }

    // Запись текста в разделяемую память
    strcpy(shm, input);

    printf("Текст успешно записан в разделяемую память.\n");

    // Отключение разделяемой памяти
    if (shmdt(shm) == -1) {
        perror("shmdt");
        exit(1);
    }

    return 0;
}

