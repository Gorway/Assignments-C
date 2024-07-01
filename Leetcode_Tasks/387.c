#include <stdio.h>
#include <stdbool.h>
#include <string.h>

int first_unique_char(const char *str) {
    int count[256] = {0}; 

    for (int i = 0; str[i]; i++) {
        count[(int)str[i]]++;
    }

    for (int i = 0; str[i]; i++) {
        if (count[(int)str[i]] == 1) {
            return i;
        }
    }

    return -1;
}

int main() {
    const char *str = "leetcode";

    int index = first_unique_char(str);

    if (index != -1) {
        printf("Первый уникальный символ в строке \"%s\" имеет индекс: %d\n", str, index);
    } else {
        printf("В строке \"%s\" нет уникальных символов.\n", str);
    }

    return 0;
}

