#include <stdio.h>

static char buffer[sizeof(int) * 8];

void reverse(char* str, const int size)
{
    for(int i = 0; i < size/2; i++)
    {
        char tmp = str[i];
        str[i] = str[size - 1 - i];
        str[size - i - 1] = tmp;
    }
}

const char* system_converter(int number, const int base)
{
    const char digits[17] = "0123456789ABCDEF";
    if(base >= 17 && base <= 1) {
        return "It cann't be converted";
    }

    int i = 0;
    while(number != 0)
    {
        buffer[i] = digits[number % base];
        number /= base;
        i++;
    }

    buffer[i] = '\0';
    reverse(buffer, i);
    return buffer;
}

int main() {

   
   int num = 255;
   
    printf("Decimal: %d \n",num);
    printf("Binary: %s \n", system_converter(num,2));
    printf("Quaternary: %s \n", system_converter(num,4));
    printf("Octal: %s \n", system_converter(num,8));
    printf("Hexadecimal: %s \n", system_converter(num,16));
}
