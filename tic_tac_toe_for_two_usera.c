#include <stdio.h>
void displayBoard(char board[3][3])
{
    printf("Current Board:\n");
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf(" %c ", board[i][j]);
            if (j < 2)
            {
                printf("|");
            }
        }
        printf("\n");
        if (i < 2)
        {
            printf("---|---|---\n");
        }
    }
    printf("\n");
}


int checkWin(char board[3][3], char player) {
    for (int i = 0; i < 3; i++) {
        if ((board[i][0] == player && board[i][1] == player && board[i][2] == player) ||
            (board[0][i] == player && board[1][i] == player && board[2][i] == player)) {
            return 1;
        }
    }
    if ((board[0][0] == player && board[1][1] == player && board[2][2] == player) ||
        (board[0][2] == player && board[1][1] == player && board[2][0] == player)) {
        return 1;
    }
    return 0;
}

int main() {
    char board[3][3] = { {' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '} };
    char currentPlayer = 'X';
    int row, col;

    printf("It's aTic Tac Toe game\n");
    printf("Player 1: X, Player 2: O\n");

    for (int turn = 0; turn < 9; turn++) {
        displayBoard(board);
        printf("Player %c, enter row (0-2) and column (0-2): ", currentPlayer);
        scanf("%d %d", &row, &col);

        if (row < 0 || row > 2 || col < 0 || col > 2 || board[row][col] != ' ') {
            printf("Invalid move. Try again.\n");
            turn--;
            continue;
        }

        
        board[row][col] = currentPlayer;

        
        if (checkWin(board, currentPlayer)) {
            displayBoard(board);
            printf("Player %c wins!\n", currentPlayer);
            break;
        }
        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
    }
    if (checkWin(board, 'X') == 0 && checkWin(board, 'O') == 0) {
        displayBoard(board);
        printf("It's a draw!\n");
    }

    return 0;
}