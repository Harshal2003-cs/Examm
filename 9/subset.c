#include <stdio.h>

int n, target;
int set[20], subset[20];

// Function to print current subset
void printSubset(int length) {
    printf("{ ");
    for (int i = 0; i < length; i++)
        printf("%d ", subset[i]);
    printf("}\n");
}

// Recursive backtracking function
void sumOfSubsets(int index, int currentSum, int subsetSize) {
    if (currentSum == target) {
        printSubset(subsetSize);
        return;
    }

    for (int i = index; i < n; i++) {
        if (currentSum + set[i] <= target) {
            subset[subsetSize] = set[i];
            sumOfSubsets(i + 1, currentSum + set[i], subsetSize + 1);
        }
    }
}

int main() {
    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter the elements:\n");
    for (int i = 0; i < n; i++)
        scanf("%d", &set[i]);

    printf("Enter the target sum: ");
    scanf("%d", &target);

    printf("Subsets with sum %d are:\n", target);
    sumOfSubsets(0, 0, 0);

    return 0;
}