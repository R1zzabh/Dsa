// Seema is tasked with implementing a program that creates a binary tree using an array of integers as input. The program should then print the tree preorder traversal.


// Help her with the program.
// Input format :

// The input consists of five integers separated by spaces. These integers represent the values of nodes in the binary tree.
// Output format :

// The first line of output displays "Preorder traversal:"

// The second line prints space-separated integers, representing the preorder traversal values.


// Refer to the sample output for the formatting specifications.
// Code constraints :

// 1 ≤ value of nodes ≤ 1000

// The input array size is fixed to 5 integers.
// Sample test cases :
// Input 1 :

// 1 2 3 4 5 

// Output 1 :

// Preorder traversal:
// 1 2 4 5 3 

// Input 2 :

// 10 98 67 45 27

// Output 2 :

// Preorder traversal:
// 10 98 45 27 67 

#include <stdio.h>
#include<stdlib.h>
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

void preorderTraversal(struct Node* root) {
    if (root == NULL) return;
    printf("%d ", root->data);
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}

struct Node* createBinaryTree(int arr[], int index) {
    if (index >= 5) return NULL;
    struct Node* root = createNode(arr[index]);
    root->left = createBinaryTree(arr, 2 * index + 1);
    root->right = createBinaryTree(arr, 2 * index + 2);
    return root;
}

int main() {
    int arr[5];
    for (int i = 0; i < 5; i++) {
        scanf("%d", &arr[i]);
    }
    
    struct Node* root = createBinaryTree(arr, 0);
    
    printf("Preorder traversal:\n");
    preorderTraversal(root);
    
    return 0;
}
