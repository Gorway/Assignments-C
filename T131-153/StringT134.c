#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the String structure
typedef struct {
    char* data;
    int size;
    int cap;
} String;

// Function to return the element at the specified position
char* at(const String* string, int pos) {
    if (pos >= 0 && pos < string->size) {
        return &(string->data[pos]);
    } else {
        return NULL;
    }
}

// Function to check if the string is empty
int empty(const String* string) {
    return string->size == 0;
}

// Function to append a character to the end of the string
void push_back(String* string, char value) {
    if (string->size == string->cap) {
        // Double the capacity if necessary
        string->cap *= 2;
        string->data = realloc(string->data, string->cap * sizeof(char));
    }
    string->data[string->size++] = value;
}

// Function to remove the last character from the string
void pop_back(String* string) {
    if (!empty(string)) {
        string->size--;
    }
}

// Function to return the first character of the string
char front(const String* string) {
    return string->size > 0 ? string->data[0] : '\0';
}

// Function to return the last character of the string
char back(const String* string) {
    return string->size > 0 ? string->data[string->size - 1] : '\0';
}

// Function to return the number of characters in the string
int size(const String* string) {
    return string->size;
}

// Function to create a new string by concatenating two strings
String concatenate(const String* string1, const String* string2) {
    String result;
    result.size = string1->size + string2->size;
    result.cap = result.size + 1; // +1 for null terminator
    result.data = malloc(result.cap * sizeof(char));

    // Copy the first string
    memcpy(result.data, string1->data, string1->size * sizeof(char));

    // Copy the second string
    memcpy(result.data + string1->size, string2->data, string2->size * sizeof(char));

    // Add null terminator
    result.data[result.size] = '\0';

    return result;
}

// Function to compare two strings
int compare(const String* string1, const String* string2) {
    return strcmp(string1->data, string2->data);
}

// Function to insert a character at the specified position in the string
void insert(String* string, int pos, char value) {
    if (pos >= 0 && pos <= string->size) {
        if (string->size == string->cap) {
            // Double the capacity if necessary
            string->cap *= 2;
            string->data = realloc(string->data, string->cap * sizeof(char));
        }

        // Shift elements to make space for the new character
        memmove(&(string->data[pos + 1]), &(string->data[pos]), (string->size - pos) * sizeof(char));

        // Insert the new character
        string->data[pos] = value;
        string->size++;
    }
}

// Function to remove a character from the specified position in the string
void erase(String* string, int pos) {
    if (pos >= 0 && pos < string->size) {
        // Shift elements to remove the character at the specified position
        memmove(&(string->data[pos]), &(string->data[pos + 1]), (string->size - pos - 1) * sizeof(char));
        string->size--;
    }
}

// Function to delete all characters from the string
void clear(String* string) {
    string->size = 0;
}

// Function to free the memory taken by the string
void destroyString(String* string) {
    free(string->data);
    string->data = NULL;
    string->size = 0;
    string->cap = 0;
}

// Example usage
int main() {
    // Initialize a String
    String myString;
    myString.size = 0;
    myString.cap = 10; // Initial capacity
    myString.data = malloc(myString.cap * sizeof(char));

    // Example usage of functions
    push_back(&myString, 'H');
    push_back(&myString, 'e');
    push_back(&myString, 'l');
    push_back(&myString, 'l');
    push_back(&myString, 'o');

    printf("Original String: %s\n", myString.data);

    pop_back(&myString);
    printf("After pop_back: %s\n", myString.data);

    printf("First character: %c\n", front(&myString));
    printf("Last character: %c\n", back(&myString));

    insert(&myString, 2, 'X');
    printf("After insert: %s\n", myString.data);

    erase(&myString, 1);
    printf("After erase: %s\n", myString.data);

    String otherString = concatenate(&myString, &myString);
    printf("Concatenated String: %s\n", otherString.data);

    printf("String comparison result: %d\n", compare(&myString, &otherString));

    // Free memory
    destroyString(&myString);
    destroyString(&otherString);

    return 0;
}

