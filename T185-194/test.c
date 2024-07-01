#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

// Функция, которую вызывает поток
void* print_tid_and_pid(void* arg) {
    pid_t pid = getpid(); // Получаем идентификатор процесса
    pthread_t tid = pthread_self(); // Получаем идентификатор потока

    // Печатаем идентификатор процесса и идентификатор потока
    printf("Thread ID: %ld, Process ID: %d\n", (long)tid, pid);

    return NULL;
}

int main() {
    pid_t pid = fork(); // Создаем процесс

    if (pid < 0) {
        // Ошибка при создании процесса
        perror("fork");
        exit(EXIT_FAILURE);
    } else if (pid == 0) {
        // Мы находимся в дочернем процессе
        // Создаем поток внутри дочернего процесса
        pthread_t thread;
        pthread_create(&thread, NULL, print_tid_and_pid, NULL);
        pthread_join(thread, NULL); // Ждем завершения потока
    } else {
        // Мы находимся в родительском процессе
        printf("Parent Process ID: %d\n", getpid());
    }

    return 0;
}

