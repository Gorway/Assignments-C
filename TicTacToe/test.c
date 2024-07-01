#include <stdio.h>

#define BOARD_SIZE 3

void clearScreen() {
    printf("\033[2J");
    printf("\033[H");
}

void displayBoard(char board[BOARD_SIZE][BOARD_SIZE]) {
    clearScreen();
    printf("Tic Tac Toe\n\n");

    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (board[i][j] == ' ') {
                printf(" %d ", i * BOARD_SIZE + j + 1);
            } else {
                printf(" %c ", board[i][j]);
            }
            if (j < BOARD_SIZE - 1) {
                printf("|");
            }
        }
        printf("\n");
        if (i < BOARD_SIZE - 1) {
            printf("-----------\n");
        }
    }
    printf("\n");
}

int isValidMove(char board[BOARD_SIZE][BOARD_SIZE], int move) {
    int row = (move - 1) / BOARD_SIZE;
    int col = (move - 1) % BOARD_SIZE;
    return (move >= 1 && move <= BOARD_SIZE * BOARD_SIZE && board[row][col] == ' ');
}

int checkWin(char board[BOARD_SIZE][BOARD_SIZE], char playerSymbol) {
    // Та же проверка на победу
}

int isBoardFull(char board[BOARD_SIZE][BOARD_SIZE]) {
    // Та же проверка на ничью
}

int main() {
    char board[BOARD_SIZE][BOARD_SIZE] = {{' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '}};
    int currentPlayer = 1;
    int move;

    do {
        displayBoard(board);

        printf("Player %c's turn\n", (currentPlayer == 1) ? 'X' : 'O');
        printf("Enter move (1-9): ");
        scanf("%d", &move);

        if (isValidMove(board, move)) {
            char playerSymbol = (currentPlayer == 1) ? 'X' : 'O';
            int row = (move - 1) / BOARD_SIZE;
            int col = (move - 1) % BOARD_SIZE;
            board[row][col] = playerSymbol;

            if (checkWin(board, playerSymbol)) {
                displayBoard(board);
                printf("Player %c wins!\n", playerSymbol);
                break;
            } else if (isBoardFull(board)) {
                displayBoard(board);
                printf("It's a draw!\n");
                break;
            } else {
                currentPlayer = (currentPlayer == 1) ? 2 : 1;
            }
        } else {
            printf("Invalid move. Try again.\n");
            while (getchar() != '\n'); // Сбросить буфер ввода
        }

    } while (1);

    return 0;
}

