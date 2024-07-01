#include <stdio.h>
#include <string.h>


struct Book {
    char title[50];
    char author[50];
    int publicationDate;
};

struct Book creatBook() {
    struct Book newBook;
    
    printf("Enter book title: ");
    scanf("%s", newBook.title);

    printf("Enter Author: ");
    scanf("%s", newBook.author);

    printf("Enter publication date: ");
    scanf("%d", &newBook.publicationDate);

    return newBook;
}

void FindBookStartingWithA(struct  Book books[], int size) {
    printf("Books starting with 'A: \n");

    for(int i = 0; i < size; i++) {
        if(books[i].title[0] == 'A') {
            printf("Title: %s, Author: %s, Year: %d\n", books[i].title,
            books[i].author, books[i].publicationDate);
        }
    }
}

int main() {

    const int size = 3;

    struct Book books[size];

    for(int i = 0; i < size; i++) {
        printf("Book: %d\n", i + 1);
        books[i] = creatBook();

    }
    FindBookStartingWithA(books, size);
}
