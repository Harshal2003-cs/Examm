#include <stdio.h>
#include <stdbool.h>

#define N 4

int board[N][N];

// Check if it's safe to place a queen at board[row][col]
bool isSafe(int row, int col) {
    int i, j;

    // Check column
    for (i = 0; i < row; i++)
        if (board[i][col])
            return false;

    // Check upper-left diagonal
    for (i = row, j = col; i >= 0 && j >= 0; i--, j--)
        if (board[i][j])
            return false;

    // Check upper-right diagonal
    for (i = row, j = col; i >= 0 && j < N; i--, j++)
        if (board[i][j])
            return false;

    return true;
}

// Solve N-Queens problem using backtracking
bool solveNQueens(int row) {
    if (row >= N)
        return true;

    for (int col = 0; col < N; col++) {
        if (isSafe(row, col)) {
            board[row][col] = 1;

            if (solveNQueens(row + 1))
                return true;

            board[row][col] = 0; // backtrack
        }
    }
    return false;
}

// Print the solution
void printBoard() {
    printf("One of the solutions:\n");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++)
            printf("%c ", board[i][j] ? 'Q' : '.');
        printf("\n");
    }
}

int main() {
    if (solveNQueens(0))
        printBoard();
    else
        printf("No solution exists.\n");

    return 0;
}
