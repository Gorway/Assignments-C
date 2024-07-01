#include <stdio.h>

int main() {

    char array[] = "Hello World";

    FILE* Newfile = fopen("newfile.txt", "w");
 
    if(Newfile == NULL) {
        perror("Can not open file\n");
        return 1;
    }

    fprintf(Newfile, "%s", array);

    
    fclose(Newfile);
    
}
