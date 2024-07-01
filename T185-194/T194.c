#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NUM_STUDENTS 3

typedef struct {
    char name[50];
    int score;
} Student;

Student students[NUM_STUDENTS] = {
    {"John", 85},
    {"Emma", 92},
    {"Michael", 78}
};

void *highest_score(void *arg) {
    Student *students = (Student *)arg;
    Student highest = students[0];

    for (int i = 1; i < NUM_STUDENTS; ++i) {
        if (students[i].score > highest.score) {
            highest = students[i];
        }
    }

    printf("Highest scoring student: %s (%d)\n", highest.name, highest.score);

    pthread_exit(NULL);
}

int main() {
    pthread_t thread;
    pthread_create(&thread, NULL, highest_score, (void *)students);
    pthread_join(thread, NULL);

    return 0;
}

