#include <stdio.h>

#define SIZE 3

void PlayBoard(char**); 

int isValidMove(char**, int, int); 

int isBoardFull(char**, char);

int main() {

    int board[SIZE][SIZE] = {{' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '}};
    int currentPlayer = 1;
    int row;
    int col;

    do {
        ShowBoard(board);

        printf("Now"



void PlayBoard(char board[size][size]) {
    printf("Tic Tac Toe\n\n");

    for(int i = 0; i < SIZE; i++) {
        for(int j = 0; j < SIZE; j++) {
            printf(" %c ", board[i][j]);
            if(j < SIZE - 1 ){
                printf("|");
            }
        }
        printf("\n");
        if(i < SIZE - 1) {
            printf("-----------\n");
        }
    }
    printf("\n");
}

int isValidMove(char[SIZE][SIZE], int row, int col) {

    return(row >= 0 && row < SIZE && col >= 0 && col < SIZE && board[row][col]
    == ' ');
}

int WinCheck(char[SIZE][SIZE], char playerSymbol) {
    for(int i = 0; i < SIZE; i++) {
        if((board[i][0] && board[i][1] && board[i][2] == playerSymbol) ||
            (board[0][i] && board[1][i] && board[2][i] == playerSymbol)) {
            return 1;
       }   
    }
        if((board[0][0] && board[1][1] && board[2][2] == playerSymbol) ||
            (board[0][2] && board[1][1] && board[2][0] == playerSymbol)) {
            return 1;
        }
        return 0;
}

int isBoardFull(char[SIZE][SIZE], char playerSymbol) {
    for(int i = 0; i < SIZE; i++) {
        for(int j = 0; j < SIZE; j++) {
            if(board[i][j] = ' ') {
                return 0;
            }
        }
    }
    retunr 1;
}


