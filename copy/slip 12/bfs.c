#include <stdio.h>
#include <time.h>

#define max 20

typedef struct {
    int data[max];
    int front, rear;
} QUEUE;

void addq(QUEUE *pq, int n) {
    pq->data[++pq->rear] = n;
}

int removeq(QUEUE *pq) {
    return pq->data[++pq->front];
}

void initq(QUEUE *pq) {
    pq->front = pq->rear = -1;
}

int isempty(QUEUE *pq) {
    return (pq->rear == pq->front);
}

void bfs(int m[5][5], int n) {
    int i, j, v, w;
    int visited[20] = {0};
    QUEUE q;
    initq(&q);

    printf("\nThe breadth first traversal is:\n");
    v = 0;
    visited[v] = 1;
    addq(&q, v);

    while (!isempty(&q)) {
        v = removeq(&q);
        printf("v %d\n", v + 1);

        for (w = 0; w < n; w++) {
            if ((m[v][w] == 1) && (visited[w] == 0)) {
                addq(&q, w);
                visited[w] = 1;
            }
        }
    }
}

int main() {
    int m[5][5] = {
        {0, 0, 1, 1, 0},
        {0, 0, 1, 0, 1},
        {0, 1, 0, 0, 0},
        {0, 0, 0, 0, 1},
        {0, 0, 0, 0, 0}
    };

    clock_t start, end;
    start = clock();

    bfs(m, 5);

    end = clock();  // Fix: assign end AFTER BFS
    double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Time taken for the Breadth First Search is %f\n", time_taken);

    return 0;
}
