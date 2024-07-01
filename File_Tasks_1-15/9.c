#include <stdio.h>
#include <stdlib.h>

#define BUFFER_SIZE 4096

int copy_file(const char* sourceFilename, const char* destinationFilename) {
    
    FILE* sourceFile, *destinationFile;
    char buffer[BUFFER_SIZE];
    size_t bytesRead;

    sourceFile = fopen(sourceFilename, "r");
    if(sourceFile == NULL) {
        perror("Error opnening source file.\n");
        return 1;
    }


    destinationFile = fopen(destinationFilename, "w");
    if(destinationFile == NULL) {
        perror("Error opnening destination file.\n");
        fclose(destinationFile);
        return 1;
    }

    while((bytesRead = fread(buffer, 1, sizeof(buffer), sourceFile)) > 0) {
        if(fwrite(buffer, 1, bytesRead, destinationFile) != bytesRead) {
            perror("Error writing to destination file.\n");
            fclose(sourceFile);
            fclose(destinationFile);
            return 1;
        }
    }

      fclose(sourceFile);
      fclose(destinationFile);

      printf("File copied successfully.\n");
      
      return 0;
}

int main() {

        const char* sourcFilename = "numbers.txt";
        const char* destinationFilename = "newfile.txt";

        if(copy_file(sourcFilename, destinationFilename) != 0) {
            printf("File copy failed.\n");
            return 1;
        }

        return 0;
}
