#include <stdio.h>
#include <stdlib.h>

struct Node {
    int key;
    struct Node *left;
    struct Node *right;
    int height;
};

int max(int a, int b) {
    return a > b ? a : b;
}

int height(struct Node *n) {
    return n ? n->height : 0;
}

struct Node* newNode(int key) {
    struct Node* n = malloc(sizeof(struct Node));
    n->key = key;
    n->left = n->right = NULL;
    n->height = 1;
    return n;
}

struct Node* rightRotate(struct Node* y) {
    struct Node* x = y->left;
    struct Node* t = x->right;
    x->right = y;
    y->left = t;
    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;
    return x;
}

struct Node* leftRotate(struct Node* x) {
    struct Node* y = x->right;
    struct Node* t = y->left;
    y->left = x;
    x->right = t;
    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;
    return y;
}

int balance(struct Node* n) {
    return n ? height(n->left) - height(n->right) : 0;
}

struct Node* insert(struct Node* n, int key) {
    if (!n) return newNode(key);
    if (key < n->key) n->left = insert(n->left, key);
    else if (key > n->key) n->right = insert(n->right, key);
    else return n;

    n->height = 1 + max(height(n->left), height(n->right));
    int b = balance(n);

    if (b > 1 && key < n->left->key) return rightRotate(n);
    if (b < -1 && key > n->right->key) return leftRotate(n);
    if (b > 1 && key > n->left->key) {
        n->left = leftRotate(n->left);
        return rightRotate(n);
    }
    if (b < -1 && key < n->right->key) {
        n->right = rightRotate(n->right);
        return leftRotate(n);
    }
    return n;
}

void preorder(struct Node* r) {
    if (r) {
        printf("%d ", r->key);
        preorder(r->left);
        preorder(r->right);
    }
}

int main() {
    struct Node* root = NULL;
    int n, x;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        root = insert(root, x);
    }
    preorder(root);
    return 0;
}
