#include <stdio.h>
#include <stdarg.h>

void print(const char* fmt, ...) {

    va_list arg;

    va_start(arg, fmt);
    
    while(*fmt != '\0') {
        if(*fmt == 'd') {
            int i = va_arg(arg, int);
            printf("%d\n", i);
        } else if(*fmt == 'c') {
            int c = va_arg(arg, int);
            printf("%c\n",c);
        } else if(*fmt == 'f') {
            double d = va_arg(arg, double);
            printf("%f\n", d);
        }
        fmt++;
    }

    va_end(arg);
}



int main() {

    print("dcff", 666, 'A', 1.666, 85.5);
}
