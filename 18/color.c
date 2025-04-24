#include <stdio.h>
#include <stdbool.h>

#define V 4  // Number of vertices

// Function to print the colors assigned to each vertex
void printColors(int color[]) {
    printf("Coloring of the graph:\n");
    for (int i = 0; i < V; i++) {
        printf("Vertex %d --> Color %d\n", i, color[i]);
    }
}

// Function to check if it's safe to assign color to a vertex
bool isSafe(int graph[V][V], int color[], int vertex, int c) {
    for (int i = 0; i < V; i++) {
        if (graph[vertex][i] == 1 && color[i] == c)
            return false;
    }
    return true;
}

// Recursive function to assign colors
bool colorGraph(int graph[V][V], int m, int color[], int vertex) {
    if (vertex == V)
        return true;

    for (int c = 1; c <= m; c++) {
        if (isSafe(graph, color, vertex, c)) {
            color[vertex] = c;

            if (colorGraph(graph, m, color, vertex + 1))
                return true;

            color[vertex] = 0;  // Backtrack
        }
    }

    return false;
}

// Main function
int main() {
    int graph[V][V] = {
        {0, 1, 1, 1},
        {1, 0, 1, 0},
        {1, 1, 0, 1},
        {1, 0, 1, 0}
    };

    int m = 3;  // Number of colors
    int color[V] = {0};

    if (colorGraph(graph, m, color, 0))
        printColors(color);
    else
        printf("No solution exists.\n");

    return 0;
}
