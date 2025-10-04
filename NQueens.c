#include <stdio.h>
#include <stdbool.h>

#define N 8   // Change this value to solve for different board sizes

// Function to print the chessboard
void printBoard(int board[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (board[i][j])
                printf(" Q ");
            else
                printf(" . ");
        }
        printf("\n");
    }
    printf("\n");
}

// Check if placing a queen at board[row][col] is safe
bool isSafe(int board[N][N], int row, int col) {
    int i, j;

    // Check this column on upper rows
    for (i = 0; i < row; i++)
        if (board[i][col])
            return false;

    // Check upper left diagonal
    for (i = row, j = col; i >= 0 && j >= 0; i--, j--)
        if (board[i][j])
            return false;

    // Check upper right diagonal
    for (i = row, j = col; i >= 0 && j < N; i--, j++)
        if (board[i][j])
            return false;

    return true;
}

// Solve NQueens recursively
bool solveNQueens(int board[N][N], int row) {
    if (row >= N) {
        printBoard(board);  // Found a solution
        return true;        // return true to stop after first solution
    }

    bool res = false;
    for (int col = 0; col < N; col++) {
        if (isSafe(board, row, col)) {
            board[row][col] = 1;   // Place queen
            res = solveNQueens(board, row + 1) || res;
            board[row][col] = 0;   // Backtrack
        }
    }
    return res;
}

int main() {
    int board[N][N] = {0};

    if (!solveNQueens(board, 0))
        printf("No solution exists\n");

    return 0;
}
