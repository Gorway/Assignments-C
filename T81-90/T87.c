#include <stdio.h>
#include <string.h>

int findLongestWordLength(char str[]) {
    int length = 0;  
    int currentLength = 0;  

    for (int i = 0; i <= strlen(str); i++) {
    
        if (str[i] == ' ' || str[i] == '\0') {
   
            if (currentLength > length) {
                length = currentLength;
            }
            currentLength = 0;  
        } else {
            currentLength++;
        }
    }

    return length;
}

int main() {
    char sentence[100];

    printf("Please enter the string: ");
    gets(sentence);

    int longestWordLength = findLongestWordLength(sentence);
    printf("Longest Word Lenght is՝ %d\n", longestWordLength);

    return 0;
}

