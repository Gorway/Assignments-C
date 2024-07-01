#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

bool is_anagram(const char *str1, const char *str2) {
    int count1[256] = {0}; 
    int count2[256] = {0};

    if (strlen(str1) != strlen(str2)) {
        return false;
    }

    for (int i = 0; str1[i] && str2[i]; i++) {
        count1[tolower(str1[i])]++;
        count2[tolower(str2[i])]++;
    }

    for (int i = 0; i < 256; i++) {
        if (count1[i] != count2[i]) {
            return false;
        }
    }

    return true;
}

int main() {
    const char *str1 = "listen";
    const char *str2 = "silent";

    if (is_anagram(str1, str2)) {
        printf("Строки \"%s\" и \"%s\" являются анаграммами.\n", str1, str2);
    } else {
        printf("Строки \"%s\" и \"%s\" не являются анаграммами.\n", str1, str2);
    }

    return 0;
}

