#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/wait.h>

#define MAX_BUFFER_SIZE 5
#define MAX_MESSAGE_LENGTH 256

struct SharedBuffer {
    char messages[MAX_BUFFER_SIZE][MAX_MESSAGE_LENGTH];
    int in; // Индекс для производителя
    int out; // Индекс для потребителя
    int count; // Количество сообщений в буфере
};

void createSharedBuffer(struct SharedBuffer** buffer);
void destroySharedBuffer(struct SharedBuffer* buffer);
void produceMessage(struct SharedBuffer* buffer, const char* message);
void consumeMessage(struct SharedBuffer* buffer, char* message);

void producer(struct SharedBuffer* buffer) {
    for (int i = 0; i < 10; ++i) {
        char message[MAX_MESSAGE_LENGTH];
        sprintf(message, "Сообщение %d", i + 1);
        produceMessage(buffer, message);
        printf("Производитель: отправлено сообщение %d\n", i + 1);
        sleep(1); // Имитация процесса производства
    }
}

void consumer(struct SharedBuffer* buffer) {
    for (int i = 0; i < 10; ++i) {
        char message[MAX_MESSAGE_LENGTH];
        consumeMessage(buffer, message);
        printf("Потребитель: получено сообщение: %s\n", message);
        sleep(2); // Имитация процесса потребления
    }
}

int main() {
    struct SharedBuffer* buffer;
    createSharedBuffer(&buffer);

    pid_t producerPid = fork();

    if (producerPid == -1) {
        perror("fork");
        exit(EXIT_FAILURE);
    }

    if (producerPid == 0) { // Дочерний процесс - производитель
        producer(buffer);
        exit(EXIT_SUCCESS);
    } else { // Родительский процесс - потребитель
        pid_t consumerPid = fork();

        if (consumerPid == -1) {
            perror("fork");
            exit(EXIT_FAILURE);
        }

        if (consumerPid == 0) { // Дочерний процесс - потребитель
            consumer(buffer);
            exit(EXIT_SUCCESS);
        } else { // Родительский процесс
            wait(NULL); // Ожидание завершения производителя
            wait(NULL); // Ожидание завершения потребителя

            destroySharedBuffer(buffer);
        }
    }

    return 0;
}

void createSharedBuffer(struct SharedBuffer** buffer) {
    int fd = shm_open("/shared_buffer", O_CREAT | O_RDWR, S_IRUSR | S_IWUSR);
    if (fd == -1) {
        perror("shm_open");
        exit(EXIT_FAILURE);
    }

    if (ftruncate(fd, sizeof(struct SharedBuffer)) == -1) {
        perror("ftruncate");
        exit(EXIT_FAILURE);
    }

    *buffer = (struct SharedBuffer*)mmap(NULL, sizeof(struct SharedBuffer), PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
    if (*buffer == MAP_FAILED) {
        perror("mmap");
        exit(EXIT_FAILURE);
    }

    close(fd);

    // Инициализация общего буфера
    (*buffer)->in = 0;
    (*buffer)->out = 0;
    (*buffer)->count = 0;
}

void destroySharedBuffer(struct SharedBuffer* buffer) {
    if (shm_unlink("/shared_buffer") == -1) {
        perror("shm_unlink");
        exit(EXIT_FAILURE);
    }
}

void produceMessage(struct SharedBuffer* buffer, const char* message) {
    if (buffer->count < MAX_BUFFER_SIZE) {
        strcpy(buffer->messages[buffer->in], message);
        buffer->in = (buffer->in + 1) % MAX_BUFFER_SIZE;
        buffer->count++;
    }
}

void consumeMessage(struct SharedBuffer* buffer, char* message) {
    if (buffer->count > 0) {
        strcpy(message, buffer->messages[buffer->out]);
        buffer->out = (buffer->out + 1) % MAX_BUFFER_SIZE;
        buffer->count--;
    }
}

