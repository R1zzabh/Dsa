// A company is designing an organizational structure to manage employees hierarchically. Each employee is represented as a node in a binary tree, where each node (positive integer) contains the employee's ID. The organization uses a level-order approach to insert employees into the tree. Each new employee is added to the next available position in the current level of the binary tree.


// The system needs to:

//     Insert new employee's ID positive integers into the organizational structure following a level-order traversal.
//     Print out the IDs of employees in the organization using an in-order traversal.


// Example


// Input:

// 1 2 3 0

// Output:

// 2 1 3

// Explanation:

// 1 is the root of the Binary tree. 2 is the left child of 1, and 3 is the right child of 1. Hence the in-order traversal is 2 1 3, which follows the rule Left Root Right.
// Input format :

// The input consists of a sequence of positive integers, where each integer represents an employee ID.

// The sequence ends with a non-positive integer (e.g., 0 or -1), which indicates the end of input.
// Output format :

// The output displays the sequence of integers representing the employee IDs in the in-order traversal of the binary tree.


// Refer to the sample output for the formatting specifications.
// Code constraints :

// 1 <= employee ID <= 100
// Sample test cases :
// Input 1 :

// 1 2 3 0

// Output 1 :

// 2 1 3 

// Input 2 :

// 1 2 3 4 5 6 7 -8

// Output 2 :

// 4 2 5 1 6 3 7 
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int id;
    struct Node* left;
    struct Node* right;
} Node;

Node* createNode(int id) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->id = id;
    newNode->left = newNode->right = NULL;
    return newNode;
}

void insert(Node** root, int id) {
    if (*root == NULL) {
        *root = createNode(id);
        return;
    }
    Node* queue[100];
    int front = 0, rear = 0;
    queue[rear++] = *root;

    while (front < rear) {
        Node* current = queue[front++];
        if (current->left == NULL) {
            current->left = createNode(id);
            return;
        } else {
            queue[rear++] = current->left;
        }
        if (current->right == NULL) {
            current->right = createNode(id);
            return;
        } else {
            queue[rear++] = current->right;
        }
    }
}

void inOrder(Node* root) {
    if (root == NULL) return;
    inOrder(root->left);
    printf("%d ", root->id);
    inOrder(root->right);
}

int main() {
    Node* root = NULL;
    int id;

    while (1) {
        scanf("%d", &id);
        if (id <= 0) break;
        insert(&root, id);
    }

    inOrder(root);
    printf("\n");
    return 0;
}
