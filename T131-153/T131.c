#include <stdio.h>
#include <string.h>

// Структура, представляющая информацию о книге
typedef struct {
    char title[100];
    char author[100];
    int year;
} Book;

// Функция для ввода данных о книге
void input_book_info(Book *book) {
    printf("Enter the title of the book: ");
    fgets(book->title, sizeof(book->title), stdin);
    book->title[strcspn(book->title, "\n")] = '\0';  // Убираем символ новой строки

    printf("Enter the author of the book: ");
    fgets(book->author, sizeof(book->author), stdin);
    book->author[strcspn(book->author, "\n")] = '\0';  // Убираем символ новой строки

    printf("Enter the publication year of the book: ");
    scanf("%d", &(book->year));

    // Очистка буфера ввода
    while (getchar() != '\n');
}

// Функция для вывода информации о книге
void print_book_info(const Book *book) {
    printf("Title: %s\n", book->title);
    printf("Author: %s\n", book->author);
    printf("Year: %d\n", book->year);
    printf("\n");
}

// Функция для вывода информации о книгах, начинающихся с буквы 'A'
void print_books_starting_with_A(const Book *books, int num_books) {
    printf("Books starting with 'A':\n");

    for (int i = 0; i < num_books; ++i) {
        if (books[i].title[0] == 'A' || books[i].title[0] == 'a') {
            print_book_info(&books[i]);
        }
    }
}

int main() {
    // Создаем массив структур Book
    Book books[3];

    // Заполняем информацию о книгах
    for (int i = 0; i < 3; ++i) {
        printf("Enter information for Book %d:\n", i + 1);
        input_book_info(&books[i]);
    }

    // Выводим информацию о всех книгах
    printf("\nInformation about all books:\n");
    for (int i = 0; i < 3; ++i) {
        printf("Book %d:\n", i + 1);
        print_book_info(&books[i]);
    }

    // Выводим информацию о книгах, начинающихся с буквы 'A'
    print_books_starting_with_A(books, 3);

    return 0;
}

