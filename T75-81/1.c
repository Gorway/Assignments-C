#include <stdio.h>
#include <string.h>

int main()
{
    struct Person {
        char name[50];
        int  age;
        float height;
    };

    struct Person person1;

    strcpy(person1.name, "Gor Petrosyan");
    person1.age = 29;
    person1.height = 169.8;

    printf("Name: %s\n", person1.name);
    printf("Age: %d\n", person1.age);
    printf("Height: %.2f\n", person1.height);
}
