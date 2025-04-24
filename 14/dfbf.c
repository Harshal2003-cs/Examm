#include <stdio.h>

#define MAX 100

int graph[MAX][MAX];  // Adjacency matrix
int visited[MAX];     // Visited array
int queue[MAX];       // Queue for BFS
int n;                // Number of vertices
int front = 0, rear = -1;

// DFS function
void DFS(int vertex) {
    printf("%d ", vertex);
    visited[vertex] = 1;

    for (int i = 0; i < n; i++) {
        if (graph[vertex][i] == 1 && !visited[i]) {
            DFS(i);
        }
    }
}

// BFS function
void BFS(int start) {
    front = 0;
    rear = -1;

    for (int i = 0; i < n; i++)
        visited[i] = 0;

    visited[start] = 1;
    queue[++rear] = start;

    while (front <= rear) {
        int current = queue[front++];
        printf("%d ", current);

        for (int i = 0; i < n; i++) {
            if (graph[current][i] == 1 && !visited[i]) {
                queue[++rear] = i;
                visited[i] = 1;
            }
        }
    }
}

int main() {
    int edges, src, dest;
    int choice, startVertex;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    // Initialize graph
    for (int i = 0; i < n; i++) {
        visited[i] = 0;
        for (int j = 0; j < n; j++) {
            graph[i][j] = 0;
        }
    }

    printf("Enter number of edges: ");
    scanf("%d", &edges);

    printf("Enter edges (format: src dest):\n");
    for (int i = 0; i < edges; i++) {
        scanf("%d %d", &src, &dest);
        graph[src][dest] = 1;
        graph[dest][src] = 1; // Undirected graph
    }

    printf("Enter starting vertex: ");
    scanf("%d", &startVertex);

    printf("Choose Traversal:\n1. DFS\n2. BFS\nEnter choice: ");
    scanf("%d", &choice);

    if (choice == 1) {
        // Reset visited array for DFS
        for (int i = 0; i < n; i++) visited[i] = 0;
        printf("DFS Traversal: ");
        DFS(startVertex);
    } else if (choice == 2) {
        printf("BFS Traversal: ");
        BFS(startVertex);
    } else {
        printf("Invalid choice!\n");
    }

    printf("\n");

    return 0;
}
