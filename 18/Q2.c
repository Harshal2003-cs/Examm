#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 100

int graph[MAX][MAX];
int queue[MAX];
bool visited[MAX];
bool dead[MAX];
int front = -1, rear = -1;
int n; // Number of vertices

void enqueue(int v) {
    if (rear == MAX - 1) return;
    if (front == -1) front = 0;
    queue[++rear] = v;
}

int dequeue() {
    if (front == -1 || front > rear) return -1;
    return queue[front++];
}

bool isLive(int v) {
    for (int i = front; i <= rear; i++)
        if (queue[i] == v)
            return true;
    return false;
}

void BFS(int start) {
    enqueue(start);
    visited[start] = true;

    while (front <= rear) {
        int e_node = dequeue();
        printf("\nE-node (exploring): %d\n", e_node);
        dead[e_node] = true;

        // Print Live Nodes
        printf("Live Nodes: ");
        for (int i = front; i <= rear; i++) {
            printf("%d ", queue[i]);
        }

        // Add unvisited neighbors
        for (int i = 0; i < n; i++) {
            if (graph[e_node][i] && !visited[i]) {
                enqueue(i);
                visited[i] = true;
            }
        }

        printf("\nDead Nodes: ");
        for (int i = 0; i < n; i++) {
            if (dead[i])
                printf("%d ", i);
        }
        printf("\n");
    }
}

int main() {
    int start;
    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &graph[i][j]);

    printf("Enter starting node (0 to %d): ", n - 1);
    scanf("%d", &start);

    BFS(start);

    return 0;
}