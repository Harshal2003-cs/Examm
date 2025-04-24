#include <stdio.h>
#include <stdlib.h>

#define max 100

// Tree node
struct Node {
    char data;
    int freq;
    struct Node *left, *right;
};

// Create new node
struct Node* createNode(char data, int freq) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->freq = freq;
    node->left = node->right = NULL;
    return node;
}

// Swap two node pointers
void swap(struct Node** a, struct Node** b) {
    struct Node* temp = *a;
    *a = *b;
    *b = temp;
}

// Sort array of node pointers by frequency (simple selection sort)
void sortNodes(struct Node* nodes[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int min_idx = i;
        for (int j = i + 1; j < n; j++) {
            if (nodes[j]->freq < nodes[min_idx]->freq) {
                min_idx = j;
            }
        }
        swap(&nodes[i], &nodes[min_idx]);
    }
}

// Build Huffman Tree using Greedy Method
struct Node* buildHuffmanTree(char data[], int freq[], int size) {
    struct Node* nodes[100];
    for (int i = 0; i < size; i++) {
        nodes[i] = createNode(data[i], freq[i]);
    }

    int n = size;
    while (n > 1) {
        sortNodes(nodes, n);

        struct Node* left = nodes[0];
        struct Node* right = nodes[1];

        struct Node* newNode = createNode('$', left->freq + right->freq);
        newNode->left = left;
        newNode->right = right;

        nodes[0] = newNode;
        for (int i = 1; i < n - 1; i++)
            nodes[i] = nodes[i + 1];

        n--;
    }

    return nodes[0];
}

// Print Huffman Codes
void printCodes(struct Node* root, int code[], int top) {
    if (root->left) {
        code[top] = 0;
        printCodes(root->left, code, top + 1);
    }

    if (root->right) {
        code[top] = 1;
        printCodes(root->right, code, top + 1);
    }

    if (!root->left && !root->right) {
        printf("%c: ", root->data);
        for (int i = 0; i < top; i++)
            printf("%d", code[i]);
        printf("\n");
    }
}

// Main
int main() {
    int n;
    printf("Enter number of characters: ");
    scanf("%d", &n);

    char data[n];
    int freq[n];

    printf("Enter characters:\n");
    for (int i = 0; i < n; i++) {
        printf("Character %d: ", i + 1);
        scanf(" %c", &data[i]);  // Note space before %c to consume newline
    }

    printf("Enter frequencies:\n");
    for (int i = 0; i < n; i++) {
        printf("Frequency for '%c': ", data[i]);
        scanf("%d", &freq[i]);
    }

    struct Node* root = buildHuffmanTree(data, freq, n);

    printf("\nHuffman Codes:\n");
    int code[max];
    printCodes(root, code, 0);

    return 0;
}
