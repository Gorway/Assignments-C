#include <ncurses.h>
#include <stdlib.h>

char board[3][3] = {{' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '}};
int currentPlayer = 1; // 1 - player X, 2 - player O
int cursorX = 0, cursorY = 0; // Cursor position

void displayBoard() {
    clear();
    
    // Print the title
    printw("Tic Tac Toe\n\n");

    // Print the current state of the board
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printw(" %c ", board[i][j]);
            if (j < 2) {
                printw("|");
            }
        }
        printw("\n");
        if (i < 2) {
            printw("-----------\n");
        }
    }

    // Indicate the current player's turn
    printw("\nPlayer %c's turn\n\n", (currentPlayer == 1) ? '1' : '2');
    printw("      ^\n");
    printw("Use <   >  to move \n");
    printw("      v \n");
    printw("Use SPACE for enter.\n");
    printw("Use 'q' for Exit.\n");

    // Display cursor marker
    move(cursorY * 2 + 1, cursorX * 4 + 1); // Move to the center of the cell
    printw("*");
}

int isValidMove(int row, int col) {
    return (row >= 0 && row < 3 && col >= 0 && col < 3 && board[row][col] == ' ');
}

void makeMove(int row, int col, char playerSymbol) {
    board[row][col] = playerSymbol;
}

int checkWin(char playerSymbol) {
    // Check rows and columns
    for (int i = 0; i < 3; i++) {
        if ((board[i][0] == playerSymbol && board[i][1] == playerSymbol && board[i][2] == playerSymbol) ||
            (board[0][i] == playerSymbol && board[1][i] == playerSymbol && board[2][i] == playerSymbol)) {
            return 1;  // Player wins
        }
    }

    // Check diagonals
    if ((board[0][0] == playerSymbol && board[1][1] == playerSymbol && board[2][2] == playerSymbol) ||
        (board[0][2] == playerSymbol && board[1][1] == playerSymbol && board[2][0] == playerSymbol)) {
        return 1;  // Player wins
    }

    return 0;  // Game continues
}

void switchPlayer() {
    currentPlayer = (currentPlayer == 1) ? 2 : 1;
}

int isBoardFull() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == ' ') {
                return 0;  // There is an empty cell, game is not over
            }
        }
    }
    return 1;  // Game board is completely filled
}

void resetGame() {
    // Reset the game board and switch the starting player
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            board[i][j] = ' ';
        }
    }
    // Ask the user to choose the starting player
    printw("Choose the starting player (X or O): ");
    refresh();
    int ch = getch();
    if (ch == 'X' || ch == 'x') {
        currentPlayer = 1;
    } else {
        currentPlayer = 2;
    }
    cursorX = cursorY = 0;
}

int main() {
    initscr();
    cbreak();
    noecho();
    keypad(stdscr, TRUE);
    curs_set(0);

    int ch;

    do {
        resetGame(); // Start a new game

        do {
            displayBoard();

            ch = getch();

            switch (ch) {
                case KEY_UP:
                    if (cursorY > 0) {
                        cursorY--;
                    }
                    break;
                case KEY_DOWN:
                    if (cursorY < 2) {
                        cursorY++;
                    }
                    break;
                case KEY_LEFT:
                    if (cursorX > 0) {
                        cursorX--;
                    }
                    break;
                case KEY_RIGHT:
                    if (cursorX < 2) {
                        cursorX++;
                    }
                    break;
                case ' ':
                    if (isValidMove(cursorY, cursorX)) {
                        char playerSymbol = (currentPlayer == 1) ? 'X' : 'O';
                        makeMove(cursorY, cursorX, playerSymbol);

                        if (checkWin(playerSymbol)) {
                            displayBoard();
                            printw("Player %c wins!\n", playerSymbol);
                            refresh();
                            napms(2000); // Pause for 2 seconds
                            break;  // Exit the loop
                        } else if (isBoardFull()) {
                            displayBoard();
                            printw("It's a draw!\n");
                            refresh();
                            napms(2000); // Pause for 2 seconds
                            break;  // Exit the loop
                        } else {
                            switchPlayer();
                        }
                    }
                    break;
            }

        } while (ch != 'q');

        clear();
        printw("Do you want to play again? (y/n): Press (q) for Exit:");
        refresh();
        ch = getch();
    } while (ch == 'y' || ch == 'Y');

    endwin();

    return 0;
}

