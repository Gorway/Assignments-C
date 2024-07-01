#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <sys/wait.h>

#define MAX_MESSAGES 100
#define SHM_NAME "/mailbox"

struct Mailbox {
    int id;
    char messages[MAX_MESSAGES][256];
    int messageCount;
};

void send_message(struct Mailbox *mailbox, const char *message) {
    if (mailbox->messageCount < MAX_MESSAGES) {
        strcpy(mailbox->messages[mailbox->messageCount++], message);
    } else {
        printf("Mailbox is full, cannot send message.\n");
    }
}

void receive_messages(struct Mailbox *mailbox) {
    printf("Received messages:\n");
    for (int i = 0; i < mailbox->messageCount; ++i) {
        printf("%s\n", mailbox->messages[i]);
    }
}

int main() {
    int shm_fd = shm_open(SHM_NAME, O_CREAT | O_RDWR, 0666);
    if (shm_fd == -1) {
        perror("shm_open");
        exit(EXIT_FAILURE);
    }

    if (ftruncate(shm_fd, sizeof(struct Mailbox)) == -1) {
        perror("ftruncate");
        exit(EXIT_FAILURE);
    }

    struct Mailbox *mailbox = mmap(NULL, sizeof(struct Mailbox), PROT_READ | PROT_WRITE, MAP_SHARED, shm_fd, 0);
    if (mailbox == MAP_FAILED) {
        perror("mmap");
        exit(EXIT_FAILURE);
    }

    mailbox->id = getpid();
    mailbox->messageCount = 0;

    pid_t pid = fork();
    if (pid < 0) {
        perror("fork");
        exit(EXIT_FAILURE);
    } else if (pid == 0) {
        // Child process (sender)
        send_message(mailbox, "Hello from child process!");
    } else {
        // Parent process (receiver)
        wait(NULL);
        receive_messages(mailbox);
    }

    if (munmap(mailbox, sizeof(struct Mailbox)) == -1) {
        perror("munmap");
        exit(EXIT_FAILURE);
    }

    if (shm_unlink(SHM_NAME) == -1) {
        perror("shm_unlink");
        exit(EXIT_FAILURE);
    }

    return 0;
}

