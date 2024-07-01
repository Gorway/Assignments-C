#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <unistd.h>
#include <sys/wait.h>

#define SHM_SIZE 1024  // Размер shared memory

int main() {
    
    char* msg1 = "Hello";
    char* msg2 = "World";
    char* msg3 = "Byeee";

    key_t key = ftok(".", 'R'); // Генерируем ключ для shared memory

    int shmid = shmget(key, SHM_SIZE, IPC_CREAT | 0666); // Создаем shared memory
    if (shmid == -1) {
        perror("shmget");
        exit(1);
    }

    char *shmaddr = (char *)shmat(shmid, NULL, 0); // Присоединяем shared memory к адресному пространству процесса
    if ((void *)shmaddr == (void *)-1) {
        perror("shmat");
        exit(1);
    }

    // Создаем три процесса
    for (int i = 0; i < 3; i++) {
        pid_t pid = fork();

        if (pid < 0) {
            perror("fork");
            exit(1);
        } else if (pid == 0) { // Дочерний процесс
            switch (i) {
                case 0:
                    strcpy(shmaddr, msg1);
                    
                    break;
                case 1:
                    *shmaddr = '\n';
                    strcpy(shmaddr + strlen(msg2), msg2);
                    
                    break;
                case 2:
                    strcpy(shmaddr + strlen(shmaddr), msg3);
                    break;
            }
            exit(0);
        }
    }

    // Ждем завершения всех дочерних процессов
    for (int i = 0; i < 3; i++) {
        wait(NULL);
    }

    // Печатаем содержимое shared memory
    printf("Содержимое shared memory: %s\n", shmaddr);

    // Отсоединяем shared memory от адресного пространства процесса
    if (shmdt((void *)shmaddr) == -1) {
        perror("shmdt");
        exit(1);
    }

    // Удаляем shared memory
    if (shmctl(shmid, IPC_RMID, NULL) == -1) {
        perror("shmctl");
        exit(1);
    }

    return 0;
}

