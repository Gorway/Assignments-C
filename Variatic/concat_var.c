#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <string.h>


char* concatenate_strings(int count, ...) {
    va_list args;
    va_start(args, count);


    char *str1 = va_arg(args, char*);
    if (str1 == NULL) {
        va_end(args);
        return NULL;
    }


    char *str2 = va_arg(args, char*);
    if (str2 == NULL) {
        va_end(args);
        return NULL;
    }


    size_t len1 = strlen(str1);
    size_t len2 = strlen(str2);
    char *result = (char *)malloc(len1 + len2 + 1);
    if (result == NULL) {
        va_end(args);
        return NULL;
    }
    strcpy(result, str1);
    strcat(result, str2);

    va_end(args);
    return result;
}

int main() {
    char *result = concatenate_strings(2, "Hello, ", "world!");
    if (result != NULL) {
        printf("%s\n", result);
        free(result);
    } else {
        printf("Failed to concatenate strings.\n");
    }
    return 0;
}
