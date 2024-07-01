#include <stdio.h>
#include <stdlib.h>

int main() {

    FILE* file;
    char ch;
    int digit_count;
    int sum;

    file = fopen("numbers.txt", "r");
    if(file == NULL) {
        printf("cannot open file\n");
        return 1;
        }

    while((ch = fgetc(file)) != EOF) {
        if(ch >= '0' && ch <= '9') {
            sum += ch - '0';
            digit_count++;
            }
    }

    fclose(file);

    if(digit_count > 0) {
        file = fopen("numbers.txt", "a");
        if(file == NULL) {
            printf("Cannot open file.\n");
            return 1;
        }

        double average = (double)sum / digit_count;
        fprintf(file, "\nAverage: %.2f\n", average);
        
        fclose(file);
    
        printf("Average has been added to the end of the file\n");
    } else {
        printf("No digits found in the file.\n");
    }

    return 0;
}
