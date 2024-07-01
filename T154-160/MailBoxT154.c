#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/wait.h>

#define MAX_MESSAGES 10
#define MAX_MESSAGE_LENGTH 256

struct Mailbox {
    int id;
    char messages[MAX_MESSAGES][MAX_MESSAGE_LENGTH];
    int messageCount;
};

void createMailbox(struct Mailbox** mailbox) {
    int fd = shm_open("/mailbox", O_CREAT | O_RDWR, S_IRUSR | S_IWUSR);
    if (fd == -1) {
        perror("shm_open");
        exit(EXIT_FAILURE);
    }

    if (ftruncate(fd, sizeof(struct Mailbox)) == -1) {
        perror("ftruncate");
        exit(EXIT_FAILURE);
    }

    *mailbox = (struct Mailbox*)mmap(NULL, sizeof(struct Mailbox), PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
    if (*mailbox == MAP_FAILED) {
        perror("mmap");
        exit(EXIT_FAILURE);
    }

    close(fd);
}

void sendMessage(struct Mailbox* mailbox, const char* message) {
    if (mailbox->messageCount < MAX_MESSAGES) {
        strcpy(mailbox->messages[mailbox->messageCount++], message);
    } else {
        printf("Mailbox is full. Message not sent.\n");
    }
}

void receiveMessages(struct Mailbox* mailbox) {
    printf("Received Messages:\n");
    for (int i = 0; i < mailbox->messageCount; ++i) {
        printf("%s\n", mailbox->messages[i]);
    }
}

void destroyMailbox() {
    if (shm_unlink("/mailbox") == -1) {
        perror("shm_unlink");
        exit(EXIT_FAILURE);
    }
}

int main() {
    struct Mailbox* mailbox;
    createMailbox(&mailbox);

    pid_t childPid = fork();

    if (childPid == -1) {
        perror("fork");
        exit(EXIT_FAILURE);
    }

    if (childPid == 0) {  // Child process (for child)
        printf("Child process is sending messages...\n");
        for (int i = 0; i < 5; ++i) {
            char message[256];
            sprintf(message, "Child message %d", i + 1);
            sendMessage(mailbox, message);
        }
        exit(EXIT_SUCCESS);
    } else {  // Parent process (for parent)
        wait(NULL);  // Wait for child process to finish

        printf("Parent process is sending messages...\n");
        for (int i = 0; i < 5; ++i) {
            char message[256];
            sprintf(message, "Parent message %d", i + 1);
            sendMessage(mailbox, message);
        }

        // Display received messages
        receiveMessages(mailbox);

        // Cleanup resources
        destroyMailbox();
    }

    return 0;
}

