#include <stdio.h>

void clearScreen() {
    printf("\033[2J");
    printf("\033[H");
}

int main() {
    char board[3][3] = {{' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '}};
    int row = 0, col = 0; // начальные координаты курсора

    clearScreen();
    printf("Tic Tac Toe\n\n");

    // Переместить курсор в начальные координаты
    printf("\033[%d;%dH", row * 2 + 2, col * 4 + 1);

    // Пример ввода
    char input;
    while (1) {
        input = getchar();
        if (input == 'q') {
            break;
        } else if (input == 'w' && row > 0) {
            printf("\033[1A"); // Переместить курсор вверх
            row--;
        } else if (input == 's' && row < 2) {
            printf("\033[1B"); // Переместить курсор вниз
            row++;
        } else if (input == 'a' && col > 0) {
            printf("\033[1D"); // Переместить курсор влево
            col--;
        } else if (input == 'd' && col < 2) {
            printf("\033[1C"); // Переместить курсор вправо
            col++;
        } else if ((input == 'x' || input == 'o') && board[row][col] == ' ') {
            // Ввести символ в текущую клетку
            board[row][col] = input;
            // Переместить курсор на следующую ячейку
            col++;
            if (col > 2) {
                col = 0;
                row++;
                if (row > 2) {
                    row = 0;
                }
            }
            // Очистить и перерисовать доску
            clearScreen();
            printf("Tic Tac Toe\n\n");
            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 3; j++) {
                    printf(" %c ", board[i][j]);
                    if (j < 2) {
                        printf("|");
                    }
                }
                printf("\n");
                if (i < 2) {
                    printf("---|---|---\n");
                }
            }
            // Переместить курсор в новые координаты
            printf("\033[%d;%dH", row * 2 + 2, col * 4 + 1);
        }
    }

    return 0;
}

