#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int weight, profit;
    float ratio;
} Item;

typedef struct {
    int level;
    int profit;
    int weight;
    float bound;
} Node;

#define MAX 100
Item items[MAX];
int n, capacity;

// Sort items by decreasing profit/weight ratio
int cmp(const void* a, const void* b) {
    float r1 = ((Item*)a)->ratio;
    float r2 = ((Item*)b)->ratio;
    return (r2 > r1) - (r2 < r1);
}

// Calculate upper bound (fractional knapsack)
float calculateBound(Node u) {
    if (u.weight >= capacity)
        return 0;

    float bound = u.profit;
    int totalWeight = u.weight;
    int i = u.level + 1;

    while (i < n && totalWeight + items[i].weight <= capacity) {
        totalWeight += items[i].weight;
        bound += items[i].profit;
        i++;
    }

    if (i < n)
        bound += (capacity - totalWeight) * items[i].ratio;

    return bound;
}

// Simulated priority queue
Node queue[MAX];
int qSize = 0;

void push(Node node) {
    queue[qSize++] = node;
}

Node pop() {
    int best = 0;
    for (int i = 1; i < qSize; i++) {
        if (queue[i].bound > queue[best].bound)
            best = i;
    }
    Node top = queue[best];
    queue[best] = queue[--qSize];
    return top;
}

int isEmpty() {
    return qSize == 0;
}

int knapsackLCBB() {
    qsort(items, n, sizeof(Item), cmp); // sort by ratio

    Node u, v;
    u.level = -1;
    u.profit = 0;
    u.weight = 0;
    u.bound = calculateBound(u);

    push(u);

    int maxProfit = 0;

    while (!isEmpty()) {
        u = pop();

        if (u.bound <= maxProfit)
            continue;

        v.level = u.level + 1;

        // Take item
        v.weight = u.weight + items[v.level].weight;
        v.profit = u.profit + items[v.level].profit;

        if (v.weight <= capacity && v.profit > maxProfit)
            maxProfit = v.profit;

        v.bound = calculateBound(v);
        if (v.bound > maxProfit)
            push(v);

        // Don't take item
        v.weight = u.weight;
        v.profit = u.profit;
        v.bound = calculateBound(v);
        if (v.bound > maxProfit)
            push(v);
    }

    return maxProfit;
}

// Main
int main() {
    printf("Enter number of items: ");
    scanf("%d", &n);

    printf("Enter knapsack capacity: ");
    scanf("%d", &capacity);

    printf("Enter profit and weight of each item:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &items[i].profit, &items[i].weight);
        items[i].ratio = (float)items[i].profit / items[i].weight;
    }

    int result = knapsackLCBB();
    printf("Maximum profit using LCBB = %d\n", result);

    return 0;
}