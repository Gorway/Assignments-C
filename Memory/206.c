#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#define MAX_SIZE 1024

// Функция для проверки, является ли строка палиндромом
int isPalindrome(char *str) {
    int left = 0;
    int right = strlen(str) - 1;
    
    while (right > left) {
        if (str[left++] != str[right--]) {
            return 0; // Не палиндром
        }
    }
    
    return 1; // Палиндром
}

int main() {
    int shmid;
    key_t key;
    char input[MAX_SIZE];

    // Создание межпроцессного ключа с помощью функции ftok()
    if ((key = ftok(".", 'A')) == -1) {
        perror("ftok");
        exit(1);
    }

    // Создание или получение разделяемой памяти
    if ((shmid = shmget(key, MAX_SIZE, IPC_CREAT | IPC_EXCL | 0666)) < 0) {
       
     if ((shmid = shmget(key, MAX_SIZE, 0666)) < 0) {
        perror("shmget");
        exit(1);
    } else {
        if(shmctl(shmid, IPC_RMID, NULL) == -1) {
            perror("shmctl");
            exit(1);
        }

     if ((shmid = shmget(key, MAX_SIZE, 0666)) < 0) {
        perror("shmget");
        exit(1);
      }
     }
    }


    // Подключение разделяемой памяти
    char *shm;
    if ((shm = shmat(shmid, NULL, 0)) == (char *) -1) {
        perror("shmat");
        exit(1);
    }
    printf("Введите текст для проверки на палиндром:\n");
    fgets(input, MAX_SIZE, stdin);

    // Удаляем символ новой строки, добавленный функцией fgets
    input[strcspn(input, "\n")] = '\0';

    // Проверяем, является ли текст палиндромом
    if (isPalindrome(input)) {
        // Записываем текст в разделяемую память
        strcpy(shm, input);
        printf("Текст является палиндромом и записан в разделяемую память.\n");

        // Создаем дочерний процесс
        pid_t pid = fork();
        if (pid == -1) {
            perror("fork");
            exit(1);
        } else if (pid == 0) { // Дочерний процесс
            printf("Дочерний процесс выводит текст из разделяемой памяти:\n");
            printf("%s\n", shm);
            exit(0);
        }
    } else {
        printf("Текст не является палиндромом.\n");
    }

    // Отключение разделяемой памяти
    if (shmdt(shm) == -1) {
        perror("shmdt");
        exit(1);
    }

    return 0;

}

