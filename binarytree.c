// Raj is given the challenge of developing a program that constructs a binary tree from a list of integer values. After constructing the tree, he needs to implement functionality to perform a postorder traversal. Finally, he should print the nodes of the tree in the postorder sequence.


// Help Raj in the challenge.
// Input format :

// The input consists of five space-separated integers, representing the values of nodes in the binary tree.
// Output format :

// The output prints the post-order traversal of the constructed binary tree.


// Refer to the sample output for formatting specifications.
// Code constraints :

// 1 ≤ value of nodes ≤ 1000
// Sample test cases :
// Input 1 :

// 1 2 3 4 5 

// Output 1 :

// 4 5 2 3 1 

// Input 2 :

// 5 3 7 2 4 

// Output 2 :

// 2 4 3 7 5 




#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

struct Node* insert(struct Node* node, int data) {
    if (node == NULL) return newNode(data);
    if (data < node->data)
        node->left = insert(node->left, data);
    else
        node->right = insert(node->right, data);
    return node;
}

void postOrder(struct Node* node) {
    if (node == NULL) return;
    postOrder(node->left);
    postOrder(node->right);
    printf("%d ", node->data);
}

int main() {
    int values[5];
    struct Node* root = NULL;

    for (int i = 0; i < 5; i++) {
        scanf("%d", &values[i]);
        root = insert(root, values[i]);
    }

    postOrder(root);
    printf("\n");
    return 0;
}
