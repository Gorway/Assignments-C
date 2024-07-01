#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STUDENTS 100
#define MAX_NAME_LENGTH 50
#define MARKS_COUNT 3

typedef struct {
    char* name;
    int id;
    int age;
    int* marks;
} Student;

void add_student(Student* student);
void display_student(Student* student);
void calculate_average(Student* student);
void find_highest_score_student(Student* students, int numStudents);
void free_memory(Student* student, int numStudents);

int main() {

    int numStudents = 0;
    printf("Enter the number of students: ");
    scanf("%d", &numStudents);
    
    if(numStudents < 0 || numStudents > MAX_STUDENTS) {
        printf("Wrong number of students\n");
        return 1;
    }

    Student* students = (Student*)malloc(numStudents * sizeof(Student));
    if(students == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    
    for(int i = 0; i < numStudents; i++) {
        add_student(&students[i]);
        display_student(&students[i]);
        calculate_average(&students[i]);
    }

    find_highest_score_student(students, numStudents);
    free_memory(students, numStudents);

    return 0;

}

void add_student(Student* students) {

    students->name = (char*)malloc(MAX_NAME_LENGTH * sizeof(char));
    if(students->name == NULL) {
        printf("Memory allocation failed");
        exit(1);
    }

    printf("Enter Student Name: ");
    scanf("%s", students->name);

    printf("Enter Student ID: ");
    scanf("%d", &students->id);

    printf("Enter Student Age: ");
    scanf("%d", &students->age);
    
    students->marks = (int*)malloc(MARKS_COUNT * sizeof(int));
    if(students->marks == NULL) {
        printf("Memory allocation failed");
        exit(1);
    }
    printf("Enter Student Marks:\n ");
    for(int i = 0; i < MARKS_COUNT; i++) {
        printf("Mark %d: ", i + 1);
        scanf("%d", &students->marks[i]);
    }
}

void display_student(Student* students) {
    printf("\nStudent Name: %s \n", students->name);
    printf("\nStudent ID: %d\n", students->id);
    printf("\nStudent Age: %d\n", students->age);
    printf("\nStudent Marks: %d, %d , %d\n", students->marks[0], students->marks[1], students->marks[2]);
}

void calculate_average(Student* students) {
   
   float average = (float)(students->marks[0] + students->marks[1] + students->marks[2]) / 3;

   printf("Average point of Student: %f\n", average); 
}

void find_highest_score_student(Student* students, int numStudents) {
  
   int maxIndex = 0;
    
   float  maxAverage = (float)(students[0].marks[0] + students[0].marks[1] + students[0].marks[2]) / 3; 

    for(int i = 1; i < numStudents; i++) {
        float currentAverage = (float)(students[i].marks[0] + students[i].marks[1] + students[i].marks[2]) / 3; 
        if(currentAverage > maxAverage) {
            maxAverage = currentAverage;
            maxIndex = i;
        }
    }

    printf("\nStudent with highest average mark:\n");
    display_student(&students[maxIndex]);
}

void free_memory(Student* students, int numStudents) {
    for(int i = 0; i < numStudents; i++) {
        free(students[i].name);
    }
    free(students);
}
