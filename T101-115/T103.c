#include <stdio.h>
#include <stdlib.h>

void resize(int** src_arr, int new_size) {

    int* new_buf = (int*)malloc(new_size * sizeof(int));
    
    if (new_buf == NULL) {

        fprintf(stderr, "Memory allocation failed.\n");
        return;
    }


    int i;
    for (i = 0; i < new_size; ++i) {
        new_buf[i] = (*src_buf)[i];
    }


    free(*src_buf);


    *src_buf = new_buf;
}

