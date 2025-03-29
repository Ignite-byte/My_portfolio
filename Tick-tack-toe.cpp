#include <stdio.h>

char board[3][3] = { {'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'} };
int player = 1; // Player 1 starts

void displayBoard() {
    printf("\n Tic-Tac-Toe Game\n");
    printf("Player 1 (X)  -  Player 2 (O)\n\n");

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf(" %c ", board[i][j]);
            if (j < 2) printf("|");
        }
        printf("\n");
        if (i < 2) printf("---+---+---\n");
    }
    printf("\n");
}

int checkWin() {
    // Check rows & columns
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2]) return 1;
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i]) return 1;
    }
    // Check diagonals
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2]) return 1;
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0]) return 1;

    return 0; // No winner yet
}

void playGame() {
    int choice, row, col;
    char mark;

    do {
        displayBoard();
        mark = (player == 1) ? 'X' : 'O';

        printf("Player %d, enter your move (1-9): ", player);
        scanf("%d", &choice);

        // Convert choice to row & col
        row = (choice - 1) / 3;
        col = (choice - 1) % 3;

        if (choice < 1 || choice > 9 || board[row][col] == 'X' || board[row][col] == 'O') {
            printf("Invalid move! Try again.\n");
        } else {
            board[row][col] = mark;
            if (checkWin()) {
                displayBoard();
                printf("?? Player %d wins! ??\n", player);
                return;
            }
            player = (player == 1) ? 2 : 1; // Switch player
        }
    } while (1); // Infinite loop until a player wins
}

int main() {
    playGame();
    return 0;
}

