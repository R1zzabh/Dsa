// Jamie needs to build a binary tree to represent a family hierarchy. Each node represents a family member, and nodes are added sequentially from top to bottom, left to right, based on user input. Jamie must then implement a function to display the family tree using level-order traversal.
// Input format :

// The first line consists of an integer n, representing the number of nodes in the binary tree.

// The second line consists of n space-separated integers, representing the elements of the binary tree.
// Output format :

// The output displays a single line containing the level order traversal of the constructed binary tree.


// Refer to the sample output for the formatting specifications.
// Code constraints :

// 1 ≤ n ≤ 20

// 1 ≤ elements ≤ 100

// The binary tree is not empty.
// Sample test cases :
// Input 1 :

// 5
// 18 2 37 4 5

// Output 1 :

// 18 2 37 4 5 

// Input 2 :

// 8
// 15 10 20 8 12 16 25 30

// Output 2 :

// 15 10 20 8 12 16 25 30 

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
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

void insert(struct Node** root, int data) {
    if (*root == NULL) {
        *root = createNode(data);
    } else {
        struct Node* queue[20];
        int front = 0, rear = 0;
        queue[rear++] = *root;

        while (front < rear) {
            struct Node* current = queue[front++];
            if (current->left == NULL) {
                current->left = createNode(data);
                return;
            } else {
                queue[rear++] = current->left;
            }
            if (current->right == NULL) {
                current->right = createNode(data);
                return;
            } else {
                queue[rear++] = current->right;
            }
        }
    }
}

void levelOrderTraversal(struct Node* root) {
    if (root == NULL) return;
    struct Node* queue[20];
    int front = 0, rear = 0;
    queue[rear++] = root;

    while (front < rear) {
        struct Node* current = queue[front++];
        printf("%d ", current->data);
        if (current->left != NULL) queue[rear++] = current->left;
        if (current->right != NULL) queue[rear++] = current->right;
    }
}

int main() {
    int n;
    scanf("%d", &n);
    struct Node* root = NULL;

    for (int i = 0; i < n; i++) {
        int data;
        scanf("%d", &data);
        insert(&root, data);
    }

    levelOrderTraversal(root);
    printf("\n");
    return 0;
}
