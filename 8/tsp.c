#include <stdio.h>
#include <stdbool.h>
#include <limits.h>

#define MAX 10

int tspNearestNeighbor(int graph[MAX][MAX], int n, int start) {
    bool visited[MAX] = {false};
    int cost = 0;
    int current = start;
    
    visited[current] = true;
    printf("Tour: %d -> ", current);

    for (int count = 1; count < n; count++) {
        int nearest = -1;
        int minDist = INT_MAX;

        for (int i = 0; i < n; i++) {
            if (!visited[i] && graph[current][i] && graph[current][i] < minDist) {
                minDist = graph[current][i];
                nearest = i;
            }
        }

        if (nearest == -1) break;

        visited[nearest] = true;
        cost += minDist;
        current = nearest;
        printf("%d -> ", current);
    }

    cost += graph[current][start];  // return to starting city
    printf("%d\n", start);
    return cost;
}

int main() {
    int graph[MAX][MAX], n, start;

    printf("Enter number of cities: ");
    scanf("%d", &n);

    printf("Enter the distance matrix:\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &graph[i][j]);

    printf("Enter starting city (0 to %d): ", n-1);
    scanf("%d", &start);

    int totalCost = tspNearestNeighbor(graph, n, start);
    printf("Total cost of tour: %d\n", totalCost);

    return 0;
}