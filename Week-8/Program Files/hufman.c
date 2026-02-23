#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

// Huffman Tree Node
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

// Sort nodes in ascending order of frequency
void sort(struct Node* arr[], int n) {
    for(int i = 0; i < n-1; i++) {
        for(int j = i+1; j < n; j++) {
            if(arr[i]->freq > arr[j]->freq) {
                struct Node* temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

// Print Huffman Codes
void printCodes(struct Node* root, int code[], int top,
                int *totalBits, int *totalFreq) {

    if(root->left) {
        code[top] = 0;
        printCodes(root->left, code, top+1, totalBits, totalFreq);
    }

    if(root->right) {
        code[top] = 1;
        printCodes(root->right, code, top+1, totalBits, totalFreq);
    }

    // Leaf node
    if(!root->left && !root->right) {
        printf("%c : ", root->data);
        for(int i = 0; i < top; i++)
            printf("%d", code[i]);
        printf("  (freq=%d, length=%d)\n", root->freq, top);

        *totalBits += root->freq * top;
        *totalFreq += root->freq;
    }
}

int main() {

    char text[] = "DATA ANALYTICS AND INTELLIGENCE LABORATORY";
    int freq[256] = {0};

    // Step 1: Count frequency
    for(int i = 0; text[i]; i++) {
        if(text[i] != ' ')
            freq[(int)text[i]]++;
    }

    struct Node* nodes[MAX];
    int n = 0;

    // Create initial nodes
    for(int i = 0; i < 256; i++) {
        if(freq[i] > 0) {
            nodes[n++] = createNode((char)i, freq[i]);
        }
    }

    // Step 2–6: Build Huffman Tree
    while(n > 1) {

        // Arrange in ascending order
        sort(nodes, n);

        // Pick two smallest
        struct Node* left = nodes[0];
        struct Node* right = nodes[1];

        // Create new internal node
        struct Node* newNode = createNode('$',
                                left->freq + right->freq);
        newNode->left = left;
        newNode->right = right;

        // Replace first two with new node
        nodes[0] = newNode;
        nodes[1] = nodes[n-1];
        n--;
    }

    struct Node* root = nodes[0];

    // Step 7–9: Generate codes & compute bits
    int code[100], totalBits = 0, totalFreq = 0;

    printf("Huffman Codes:\n\n");
    printCodes(root, code, 0, &totalBits, &totalFreq);

    printf("\nTotal Compressed Bits = %d\n", totalBits);

    float avg = (float)totalBits / totalFreq;
    printf("Average Code Length = %.2f bits\n", avg);

    return 0;
}