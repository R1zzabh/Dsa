// Divu wants a program to analyze a binary tree by traversing it in two different ways. The program begins by prompting for an integer n, indicating the number of nodes in the binary tree. Divu then provides n integers representing the values of these nodes. The program constructs the binary tree from the provided values and performs two types of traversals:


// Forward In-order Traversal: It traverses the binary tree in order, printing each node's value as it visits.

// Reverse In-order Traversal: It traverses the binary tree in order but prints each node's value in reverse order.


// After conducting these traversals, the program prints the results.
// Input format :

// The first line consists of an integer n, representing the number of nodes in the binary tree.

// The second line consists of n space-separated integers representing the values of the nodes in the binary tree.
// Output format :

// The first line prints the in-order traversal of the binary tree, where each node's value is printed as it is visited.

// The second line prints the in-order traversal of the binary tree in reverse, where each node's value is printed in reverse order.


// Refer to the sample output for the formatting specifications.
// Code constraints :

// The input integers should be unique.

// 1 ≤ n ≤ 15

// 1 ≤ Node values ≤ 50
// Sample test cases :
// Input 1 :

// 5
// 9 8 7 6 5

// Output 1 :

// 6 8 5 9 7 
// 7 9 5 8 6 

// Input 2 :

// 8
// 1 2 3 4 5 6 7 8

// Output 2 :

// 8 4 2 5 1 6 3 7 
// 7 3 6 1 5 2 4 8 
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

struct Node* insert(struct Node* node, int data) {
    if (node == NULL) return createNode(data);
    if (data < node->data)
        node->left = insert(node->left, data);
    else
        node->right = insert(node->right, data);
    return node;
}

void inOrderTraversal(struct Node* root) {
    if (root == NULL) return;
    inOrderTraversal(root->left);
    printf("%d ", root->data);
    inOrderTraversal(root->right);
}

void reverseInOrderTraversal(struct Node* root) {
    if (root == NULL) return;
    reverseInOrderTraversal(root->right);
    printf("%d ", root->data);
    reverseInOrderTraversal(root->left);
}

int main() {
    int n;
    scanf("%d", &n);
    struct Node* root = NULL;
    int value;

    for (int i = 0; i < n; i++) {
        scanf("%d", &value);
        root = insert(root, value);
    }

    inOrderTraversal(root);
    printf("\n");
    reverseInOrderTraversal(root);
    printf("\n");

    return 0;
}
