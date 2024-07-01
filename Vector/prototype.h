#include <stdio.h>

typedef struct {
    int* vec;
    int size;
    int cap;
} Vector;

int at(Vector* vector);

int empty(const Vector* vector);

void push_back( Vector*, int value);

void pop_back(Vector* vector);

int front(const Vector* vector);

int back(const Vector* vector);

int size(const Vector* vector);

int capacity(const Vector* vector);

void insert(Vector* vector, int pos, int value);

void erase(Vector* vector, int pos);

void clear(Vector* vector);

void shrink_to_fit(Vector* vector);

void initializeVector(Vector* vector, int initialCapacity);

void destroyVector(Vector* vector);


