#include <stdio.h>
#include <string.h>

int binaryToDecimal(const char *binaryString) {

    int length = strlen(binarystrig);
    int decimalnum = 0;

    for(int i = 0; i < length; i++) {

        decimalnum = decimalnum * 2 + ( binarystring[i] - '0');
    }

    return decimalnum;
}
