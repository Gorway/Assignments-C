#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *data;    
    size_t size; 
    size_t capacity; 
} Vector;

// Инициализация вектора
void init_vector(Vector *vec) {
    vec->data = NULL;
    vec->size = 0;
    vec->capacity = 0;
}


void push_back(Vector *vec, int value) {
    if (vec->size >= vec->capacity) {

        vec->capacity = (vec->capacity == 0) ? 1 : vec->capacity * 2;
        vec->data = realloc(vec->data, vec->capacity * sizeof(int));
    }
    vec->data[vec->size++] = value;
}


void pop_back(Vector *vec) {
    if (vec->size > 0) {
        vec->size--; 
    } else {
        printf("Вектор пуст, невозможно удалить элемент.\n");
    }
}

int main() {
    Vector vec;
    init_vector(&vec);

    push_back(&vec, 1);
    push_back(&vec, 2);
    push_back(&vec, 3);

    printf("Исходный вектор: ");
    for (size_t i = 0; i < vec.size; ++i) {
        printf("%d ", vec.data[i]);
    }
    printf("\n");

    pop_back(&vec);

    printf("Вектор после удаления последнего элемента: ");
    for (size_t i = 0; i < vec.size; ++i) {
        printf("%d ", vec.data[i]);
    }
    printf("\n");

    free(vec.data);

    return 0;
}

