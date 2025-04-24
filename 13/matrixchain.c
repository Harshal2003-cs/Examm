#include <stdio.h>
#include <limits.h>

// Function to find the minimum number of multiplications
int MatrixChainOrder(int p[], int n) {
    int m[n][n];

    // m[i][j] = Minimum number of scalar multiplications needed to compute the matrix A[i]A[i+1]...A[j]
    for (int i = 1; i < n; i++)
        m[i][i] = 0;

    for (int L = 2; L < n; L++) { // L is chain length
        for (int i = 1; i < n - L + 1; i++) {
            int j = i + L - 1;
            m[i][j] = INT_MAX;
            for (int k = i; k < j; k++) {
                int q = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];
                if (q < m[i][j])
                    m[i][j] = q;
            }
        }
    }

    return m[1][n - 1]; // Minimum cost to multiply from matrix 1 to n-1
}

int main() {
    int n;

    printf("Enter number of matrices: ");
    scanf("%d", &n);

    int p[n + 1];
    printf("Enter dimensions (array of size %d):\n", n + 1);
    for (int i = 0; i <= n; i++) {
        scanf("%d", &p[i]);
    }

    int minMultiplications = MatrixChainOrder(p, n + 1);
    printf("Minimum number of multiplications is: %d\n", minMultiplications);

    return 0;
}
