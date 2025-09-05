#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node *left, *right;
};

// Function to create a new node
struct Node* newNode(int value) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = value;
    temp->left = temp->right = NULL;
    return temp;
}

 
struct Node* insert(struct Node* root, int value) {
    if (root == NULL) return newNode(value);

    if (value < root->data)
        root->left = insert(root->left, value);
    else if (value > root->data)
        root->right = insert(root->right, value);

    return root;
}

 
int findMin(struct Node* root) {
    if (root == NULL) {
        printf("Tree is empty!\n");
        return -1;
    }
    while (root->left != NULL)
        root = root->left;
    return root->data;
}


int findMax(struct Node* root) {
    if (root == NULL) {
        printf("Tree is empty!\n");
        return -1;
    }
    while (root->right != NULL)
        root = root->right;
    return root->data;
}

int main() {
    struct Node* root = NULL;
    int n, value, i;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    printf("Enter %d values:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &value);
        root = insert(root, value);
    }

    printf("\nSmallest element = %d\n", findMin(root));
    printf("Largest element  = %d\n", findMax(root));

    return 0;
}
