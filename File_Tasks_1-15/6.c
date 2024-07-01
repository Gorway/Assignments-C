#include <stdio.h>
#include <stdio.h>

int main() {

  char text;

  FILE *file = fopen("newfile.txt", "r");

  if(file == NULL) {
      printf("cannot open the file\n");
      return 1;
  }

  printf("Contents of the file: ");
  while((text = fgetc(file)) != EOF) {
      printf("%c", text);
      }

      fclose(file);
}
