#include <stdio.h>
#include <stdbool.h>

#define MAX_VERTICES 10  // Maximum number of vertices (you can change this as needed)

// Function to print the cycle
void printSolution(int path[], int n) {
    printf("Hamiltonian Cycle exists: ");
    for (int i = 0; i < n; i++)
        printf("%d ", path[i]);
    // print the starting vertex again to show cycle
    printf("%d\n", path[0]);
}

// Check if the current vertex can be added to the path
bool isSafe(int v, int graph[MAX_VERTICES][MAX_VERTICES], int path[], int pos) {
    // Check if this vertex is adjacent to the previous vertex
    if (graph[path[pos - 1]][v] == 0)
        return false;

    // Check if the vertex is already included in the path
    for (int i = 0; i < pos; i++)
        if (path[i] == v)
            return false;

    return true;
}

// Recursive function to solve the Hamiltonian Cycle problem
bool hamCycleUtil(int graph[MAX_VERTICES][MAX_VERTICES], int path[], int pos, int n) {
    // Base case: If all vertices are in the path
    if (pos == n) {
        // Check if there is an edge from the last vertex to the first
        if (graph[path[pos - 1]][path[0]] == 1)
            return true;
        else
            return false;
    }

    // Try different vertices as the next candidate in the path
    for (int v = 1; v < n; v++) {
        if (isSafe(v, graph, path, pos)) {
            path[pos] = v;

            if (hamCycleUtil(graph, path, pos + 1, n))
                return true;

            // Backtrack
            path[pos] = -1;
        }
    }

    return false;
}

// Solves the Hamiltonian Cycle problem
bool hamCycle(int graph[MAX_VERTICES][MAX_VERTICES], int n) {
    int path[MAX_VERTICES];
    for (int i = 0; i < n; i++)
        path[i] = -1;

    path[0] = 0;  // Start at vertex 0

    if (hamCycleUtil(graph, path, 1, n) == false) {
        printf("No Hamiltonian Cycle exists.\n");
        return false;
    }

    printSolution(path, n);
    return true;
}

// Main function
int main() {
    int n, graph[MAX_VERTICES][MAX_VERTICES];

    // Take input for the number of vertices
    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    // Take input for the adjacency matrix
    printf("Enter the adjacency matrix (1 for an edge, 0 for no edge):\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    // Check for Hamiltonian cycle
    if (!hamCycle(graph, n))
        printf("No Hamiltonian Cycle exists.\n");

    return 0;
}
 /*
    // Example graph (adjacency matrix)
    int graph[V][V] = {
        {0, 1, 0, 1, 0},
        {1, 0, 1, 1, 0},
        {0, 1, 0, 0, 1},
        {1, 1, 0, 0, 1},
        {0, 0, 1, 1, 0}
    };

    // Check for Hamiltonian cycle in the given graph
    if (!hamCycle(graph))
        printf("No Hamiltonian Cycle exists.\n");

    return 0;
}
*/