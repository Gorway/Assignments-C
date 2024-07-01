#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>

void my_fprintf(FILE *stream, const char *format, ...) {
    va_list args;
    va_start(args, format);

    // Переменные для обработки форматной строки
    char *p = (char *)format;
    char *sval;
    int ival;
    double dval;

    while (*p) {
        if (*p == '%') {
            switch (*++p) {
                case 'd':
                    ival = va_arg(args, int);
                    char buf[20]; // достаточный размер буфера
                    int n = sprintf(buf, "%d", ival);
                    write(fileno(stream), buf, n);
                    break;
                case 'f':
                    dval = va_arg(args, double);
                    char buf2[20]; // достаточный размер буфера
                    int m = sprintf(buf2, "%f", dval);
                    write(fileno(stream), buf2, m);
                    break;
                case 's':
                    for (sval = va_arg(args, char *); *sval; sval++)
                        write(fileno(stream), sval, 1);
                    break;
                default:
                    write(fileno(stream), p, 1);
                    break;
            }
        } else {
            write(fileno(stream), p, 1);
        }
        p++;
    }

    va_end(args);
}

int main() {
    FILE *file = fopen("output.txt", "w");
    if (file != NULL) {
        my_fprintf(file, "Hello, %s! The answer is %d\n", "world", 42);
        fclose(file);
    } else {
        printf("Error opening file!\n");
    }
    return 0;
}

