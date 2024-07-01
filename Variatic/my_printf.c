#include <unistd.h>
#include <stdarg.h>
#include <stdio.h>


void my_printf(const char *format, ...) {
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
                    write(STDOUT_FILENO, buf, n);
                    break;
                case 'f':
                    dval = va_arg(args, double);
                    char buf2[20]; // достаточный размер буфера
                    int m = sprintf(buf2, "%f", dval);
                    write(STDOUT_FILENO, buf2, m);
                    break;
                case 's':
                    for (sval = va_arg(args, char *); *sval; sval++)
                        write(STDOUT_FILENO, sval, 1);
                    break;
                default:
                    write(STDOUT_FILENO, p, 1);
                    break;
            }
        } else {
            write(STDOUT_FILENO, p, 1);
        }
        p++;
    }

    va_end(args);
}

int main() {
    my_printf("Hello, %s! The answer is %d\n", "world", 42);
    return 0;
}

