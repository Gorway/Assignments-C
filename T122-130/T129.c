#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Структура для представления даты
struct Date {
    int day;
    int month;
    int year;
};

// Структура для представления персоны
struct Person {
    char name[50];
    char surname[50];
    int age;
    struct Date birthdate;
};

// Функция для заполнения данных о персонах
void fillData(struct Person* people, int size) {
    for (int i = 0; i < size; ++i) {
        printf("Enter details for person %d:\n", i + 1);
        printf("Name: ");
        scanf("%s", people[i].name);
        printf("Surname: ");
        scanf("%s", people[i].surname);
        printf("Age: ");
        scanf("%d", &people[i].age);
        printf("Birthdate (DD MM YYYY): ");
        scanf("%d %d %d", &people[i].birthdate.day, &people[i].birthdate.month, &people[i].birthdate.year);
    }
}

// Функция для вычисления возраста персоны на основе текущей даты
int calculateAge(struct Person person, struct Date currentDate) {
    int age = currentDate.year - person.birthdate.year;
    if (currentDate.month < person.birthdate.month || (currentDate.month == person.birthdate.month && currentDate.day < person.birthdate.day)) {
        age--;
    }
    return age;
}

// Функция для нахождения самого старшего человека в массиве
struct Person findOldestPerson(struct Person* people, int size) {
    struct Person oldest = people[0];
    for (int i = 1; i < size; ++i) {
        if (people[i].age > oldest.age) {
            oldest = people[i];
        }
    }
    return oldest;
}

// Функция для сортировки массива по возрасту
void sortPeople(struct Person* people, int size) {
    for (int i = 0; i < size - 1; ++i) {
        for (int j = 0; j < size - i - 1; ++j) {
            if (people[j].age > people[j + 1].age) {
                struct Person temp = people[j];
                people[j] = people[j + 1];
                people[j + 1] = temp;
            }
        }
    }
}

// Функция для удаления пенсионеров (возраст больше 63)
void removeRetirees(struct Person** people, int* size) {
    struct Person* newArray = NULL;
    int newSize = 0;

    for (int i = 0; i < *size; ++i) {
        if ((*people)[i].age <= 63) {
            // Копирование только тех элементов, чей возраст меньше или равен 63
            if (newArray == NULL) {
                newArray = (struct Person*)malloc(sizeof(struct Person));
            } else {
                newArray = (struct Person*)realloc(newArray, (newSize + 1) * sizeof(struct Person));
            }
            newArray[newSize++] = (*people)[i];
        }
    }

    // Освобождение памяти от старого массива
    free(*people);

    // Переопределение указателя на новый массив
    *people = newArray;
    *size = newSize;
}

int main() {
    srand(time(NULL));

    int size;
    printf("Enter the number of people: ");
    scanf("%d", &size);

    // Выделение памяти для массива Person
    struct Person* people = (struct Person*)malloc(size * sizeof(struct Person));

    // Заполнение данных о персонах
    fillData(people, size);

    // Получение текущей даты
    struct tm* currentTime;
    time_t t;
    time(&t);
    currentTime = localtime(&t);
    struct Date currentDate = {
        .day = currentTime->tm_mday,
        .month = currentTime->tm_mon + 1, // tm_mon начинается с 0
        .year = currentTime->tm_year + 1900 // tm_year возвращает текущий год минус 1900
    };

    // Вывод возраста для каждой персоны
    printf("\nAge of each person:\n");
    for (int i = 0; i < size; ++i) {
        int age = calculateAge(people[i], currentDate);
        printf("%s %s: %d years\n", people[i].name, people[i].surname, age);
    }

    // Нахождение самого старшего человека
    struct Person oldestPerson = findOldestPerson(people, size);
    printf("\nOldest person:\n");
    printf("Name: %s %s\n", oldestPerson.name, oldestPerson.surname);
    printf("Age: %d years\n", oldestPerson.age);

    // Сортировка людей по возрасту
    sortPeople(people, size);

    // Вывод отсортированного массива
    printf("\nSorted array by age:\n");
    for (int i = 0; i < size; ++i) {
        printf("%s %s: %d years\n", people[i].name, people[i].surname, people[i].age);
    }

    // Удаление пенсионеров
    removeRetirees(&people, &size);

    // Вывод массива после удаления
    printf("\nArray after removing retirees:\n");
    for (int i = 0; i < size; ++i) {
        printf("%s %s: %d years\n", people[i].name, people[i].surname, people[i].age);
    }

    // Освобождение выделенной памяти
    free(people);

    return 0;
}

