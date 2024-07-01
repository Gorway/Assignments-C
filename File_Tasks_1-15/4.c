#include <stdio.h>

void add_text(char* text) {

    FILE*  file = fopen("newfile.txt", "a");

    if(file == NULL) {
        printf("Cannot open file.\n");
        return ;
        }

    fprintf(file, "%s\n", text);

    fclose(file);
}

int main () {

    char* text = "New text";

    add_text(text);
}
    
