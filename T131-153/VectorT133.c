#include <stdio.h>
#include <stdlib.h>


void initVector(Vector* vector, int startCapacity) {

    vector->vec = (int*)malloc(startCapacity * sizeof(int));

    if(vector->vec == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    vector->size = 0;
    vector->cap = startCapacity;
}

void push_back( Vector*, int value) {

        if(vector->size == vector->capacity) {
            vector->cap *= 2;
            vector->vec = (int*)realloc(vector->vec, vector->cap * sizeof(int));
            if(vec->vec == NULL) {
                printf("Memory allocation failed.\n");
                exit(1);
            }
        }

        vector->vec[size++] = value;
}

int at(const Vector* vector, int pos) {

    if(pos >= 0 && pos < vector->size) {
        return vector->vec[pos];
    } else {
        printf("Error\n");
        }
}


int  empty(const Vector* vector) {
    if(vector->size == 0) {
        return 1; 
    } else {
        return 0;
    }
}

void pop_back(Vector* vector) {
    if(vector->size > 0;) {
        vector->size--;
        }
}

int front(const Vector* vector) {
    if(vector->size > 0) {
        return vector->vec[0];
    }
}

int back(const Vector* vector) {
    if(vector->size > 0) {
        return vector->vec[size-1];
    }
}

int size(const Vector* vector) {
    return vector->size;
}

int capacity(const Vector* vector) {
    return vector->capacity;
}

void insert(Vector* vector, int pos, int value) {
 
    if(pos < 0 || pos > vector->size) {
        printf("Wrong position for inster!.\n");
        return;
    }

    if(vector->size == vector->cap) {
        vector->cap *= 2;
        vector->vec = (int*)realloc(vector->vec, vector->cap * sizeof(int));
        if(vector->vec == NULL) {
            printf("Memory allocation failed.\n");
            exit(1);
        }
    }
    
    for(int i = vector->size; i > pos; --i) {
        vector->vec[i] = vector->vec[i - 1];
    }

    vector->vec[pos] = value;
    vector->size++;
}

void erase(Vector* vector, int pos) {
    if(pos > 0 && pos < vector->size) {

        for(int i = pos; i < vector->size - 1; i++) {
            vector->vec[i] = vector->vec[i + 1];
        }
        vector->size--;
    }
}

void clear(Vector* vector) {
    
    vector->size = 0;
}

void shrink_to_fit(Vector* vector) {
    vector->cap = vector->size;
    vector->vec = (int*)realloc(vector->vec, vector->cap * sizeof(int));
    if(vector->cap == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
}

void destroyVector(Vector* vector) {

    free(vector->vec);
    vector->vec = NULL;
    vector->size = 0;
    vector->cap = 0;
}


