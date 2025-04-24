#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int adj[MAX][MAX];   // Adjacency matrix
int visited[MAX];    // Visited array
int stack[MAX];      // Stack to store topological order
int top = -1;

// Function to add edge
void addEdge(int u, int v) {
    adj[u][v] = 1;
}

// DFS function for topological sort
void dfs(int v, int vertices) {
    visited[v] = 1;

    for (int i = 0; i < vertices; i++) {
        if (adj[v][i] && !visited[i]) {
            dfs(i, vertices);
        }
    }

    stack[++top] = v;  // Push current node to stack
}

// Function to perform topological sort
void topologicalSort(int vertices) {
    for (int i = 0; i < vertices; i++) {
        visited[i] = 0;
    }

    for (int i = 0; i < vertices; i++) {
        if (!visited[i]) {
            dfs(i, vertices);
        }
    }

    printf("\nTopological Sort Order:\n");
    while (top >= 0) {
        printf("%d ", stack[top--]);
    }
    printf("\n");
}

int main() {
    int vertices, edges, u, v;

    printf("Enter number of vertices: ");
    scanf("%d", &vertices);

    printf("Enter number of edges: ");
    scanf("%d", &edges);

    printf("Enter edges (u v) where u -> v:\n");
    for (int i = 0; i < edges; i++) {
        scanf("%d %d", &u, &v);
        addEdge(u, v);
    }

    topologicalSort(vertices);

    return 0;
}