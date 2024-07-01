#include <stdio.h>
#include <ctype.h>

int main() {
    char text[1000];
    int vowels = 0, consonants = 0;
    
    printf("Введите текст: ");
    gets(text);

    
    for (int i = 0; text[i] != '\0'; i++) {
        char ch = tolower(text[i]);
        
        if (ch >= 'a' && ch <= 'z') {
            if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') {
                vowels++;
            } else {
                consonants++;
            }
        }
    }
    
    printf("Количество гласных букв: %d\n", vowels);
    printf("Количество согласных букв: %d\n", consonants);
    
    return 0;
}

