#include <stdio.h>
#include <stdbool.h>

#define MAX 10  // Maximum number of queens (you can change this as needed)

// Function to print the chessboard
void printSolution(int board[MAX][MAX], int N) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (board[i][j] == 1)
                printf("Q ");
            else
                printf(". ");
        }
        printf("\n");
    }
    printf("\n");
}

// Function to check if a queen can be placed at board[row][col]
bool isSafe(int board[MAX][MAX], int row, int col, int N) {
    // Check the column
    for (int i = 0; i < row; i++) {
        if (board[i][col] == 1)
            return false;
    }

    // Check the left diagonal
    for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--) {
        if (board[i][j] == 1)
            return false;
    }

    // Check the right diagonal
    for (int i = row - 1, j = col + 1; i >= 0 && j < N; i--, j++) {
        if (board[i][j] == 1)
            return false;
    }

    return true;
}

// Function to solve N Queens problem using Backtracking
bool solveNQUtil(int board[MAX][MAX], int row, int N) {
    // Base case: If all queens are placed, return true
    if (row >= N) {
        return true;
    }

    // Consider this row and try placing the queen in all columns one by one
    for (int col = 0; col < N; col++) {
        // Check if it's safe to place the queen at board[row][col]
        if (isSafe(board, row, col, N)) {
            // Place the queen
            board[row][col] = 1;

            // Recur to place the queen in the next row
            if (solveNQUtil(board, row + 1, N))
                return true;

            // Backtrack: If placing queen in board[row][col] doesn't lead to a solution
            board[row][col] = 0;
        }
    }

    // If the queen can't be placed in any column, return false
    return false;
}

// Function to solve the N Queens problem
bool solveNQ(int N) {
    int board[MAX][MAX] = {0};  // Initialize the board with all 0's (no queens placed)

    // Call the utility function to solve the problem
    if (solveNQUtil(board, 0, N)) {
        printSolution(board, N);
        return true;
    }

    printf("Solution does not exist.\n");
    return false;
}

// Main function
int main() {
    int N;

    // Take input for the number of queens
    printf("Enter the number of queens: ");
    scanf("%d", &N);

    // Solve the N Queens problem
    if (!solveNQ(N))
        printf("No solution exists.\n");

    return 0;
}
