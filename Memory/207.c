#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/wait.h>

#define SHM_SIZE 1024

int main() {
    int shmid;
    key_t key;
    pid_t pid;

    // Создание межпроцессного ключа с помощью функции ftok()
    if ((key = ftok(".", 'A')) == -1) {
        perror("ftok");
        exit(1);
    }

    // Создание разделяемой памяти
    if ((shmid = shmget(key, SHM_SIZE, IPC_CREAT | 0666)) < 0) {
        perror("shmget");
        exit(1);
    }

    // Создание дочернего процесса
    if ((pid = fork()) < 0) {
        perror("fork");
        exit(1);
    } else if (pid == 0) { // Дочерний процесс
        // Подключение разделяемой памяти
        char *shm;
        if ((shm = shmat(shmid, NULL, 0)) == (char *) -1) {
            perror("shmat");
            exit(1);
        }

        // Ожидание записи данных в разделяемую память
        printf("Дочерний процесс ожидает команды...\n");
        while (strlen(shm) == 0) {
            sleep(1); // Пауза для снижения нагрузки на процессор
        }

        // Выполнение команды, записанной в разделяемую память
        printf("Дочерний процесс выполняет команду: %s\n", shm);
        system(shm); // Выполнение команды
        printf("Дочерний процесс завершил выполнение команды.\n");

        // Отключение разделяемой памяти
        if (shmdt(shm) == -1) {
            perror("shmdt");
            exit(1);
        }
    } else { // Родительский процесс
        // Подключение разделяемой памяти
        char *shm;
        if ((shm = shmat(shmid, NULL, 0)) == (char *) -1) {
            perror("shmat");
            exit(1);
        }

        // Ввод команды для выполнения
        char command[SHM_SIZE];
        printf("Введите команду Linux для выполнения: ");
        fgets(command, sizeof(command), stdin);

        // Запись команды в разделяемую память
        strcpy(shm, command);

        // Ожидание завершения дочернего процесса
        wait(NULL);

        // Отключение разделяемой памяти
        if (shmdt(shm) == -1) {
            perror("shmdt");
            exit(1);
        }

        // Удаление разделяемой памяти
        if (shmctl(shmid, IPC_RMID, NULL) == -1) {
            perror("shmctl");
            exit(1);
        }
    }

    return 0;
}

