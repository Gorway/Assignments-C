#include <stdio.h>

void drawRectangle(int width, int height) {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            if (i == 0 || i == height - 1 || j == 0 || j == width - 1) {
                printf("* ");
            } else {
                printf("  ");
            }
        }
        printf("\n");
    }
}

int main() {
    int width, height;

    printf("Enter width: ");
    scanf("%d", &width);

    printf("Enter height: ");
    scanf("%d", &height);

    drawRectangle(width, height);

    return 0;
}

