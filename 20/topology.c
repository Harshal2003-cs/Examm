#include <stdio.h>
#include <stdlib.h>
#include<time.h>


#define MAX 100

typedef struct {
    int top;
    int Data[MAX];
} STACK;

void initstack(STACK *ps) {
    ps->top = -1;
}

void push(STACK *ps, int num) {
    if (ps->top < MAX - 1) {
        ps->top++;
        ps->Data[ps->top] = num;
    }
}

int isfull(STACK *ps) {
    return (ps->top == MAX - 1);
}

int isempty(STACK *ps) {
    return (ps->top == -1);
}

int pop(STACK *ps) {
    if (!isempty(ps))
        return ps->Data[ps->top--];
    return -1;
}

void topologicalsort(int m[5][5], int n) {
    int i, j, w, v;
    int visit[20] = {0};
    int indeg[100] = {0};

    // Calculate in-degrees
    for (j = 0; j < n; j++) {
        for (i = 0; i < n; i++) {
            indeg[j] += m[i][j];
        }
    }

    STACK s;
    initstack(&s);

    printf("Topological Order: ");

    while (1) {
        int pushed = 0;
        for (v = 0; v < n; v++) {
            if ((visit[v] == 0) && (indeg[v] == 0)) {
                visit[v] = 1;
                push(&s, v);
                printf("%d ", v + 1); // display vertex as 1-based index
                pushed = 1;
            }
        }

        if (isempty(&s) || !pushed)
            break;

        v = pop(&s);
        for (w = 0; w < n; w++) {
            if (m[v][w] == 1) {
                indeg[w]--;
            }
        }
    }

    printf("\n");
}

int main() {
    int n = 5;
    int m[5][5] = {
        {0, 1, 1, 0, 0},
        {0, 0, 0, 1, 0},
        {0, 0, 0, 1, 1},
        {0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0}
    };
    clock_t start,end;
    topologicalsort(m, n);
    start=clock();
    double time_taken=((double)(end-start))/CLOCKS_PER_SEC;
    printf("\n time taken %f",time_taken);

    return 0;
}
