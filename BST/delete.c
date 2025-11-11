#include <stdio.h>
#include <stdlib.h>

/* Define structure for BST Node */
typedef struct Node {
    int data;
    struct Node *left;
    struct Node *right;
} Node;

/* Function to create a new node */
Node* createNode(int value) {
    Node *newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

/* Function to insert a new node in the BST */
Node* insert(Node *root, int value) {
    if (root == NULL)
        return createNode(value);

    if (value < root->data)
        root->left = insert(root->left, value);
    else if (value > root->data)
        root->right = insert(root->right, value);
    else
        printf("Duplicate values are not allowed.\n");

    return root;
}

/* Function to find the minimum value node in the BST */
Node* findMin(Node *root) {
    while (root != NULL && root->left != NULL)
        root = root->left;
    return root;
}

/* Function to delete a node from the BST */
Node* deleteNode(Node *root, int value) {
    Node *temp;

    if (root == NULL) {
        printf("Value not found in the tree.\n");
        return root;
    }

    if (value < root->data)
        root->left = deleteNode(root->left, value);
    else if (value > root->data)
        root->right = deleteNode(root->right, value);
    else {
        /* Node to be deleted found */
        if (root->left == NULL && root->right == NULL) {
            /* Case 1: No child */
            free(root);
            root = NULL;
        }
        else if (root->left == NULL) {
            /* Case 2: One child (right) */
            temp = root;
            root = root->right;
            free(temp);
        }
        else if (root->right == NULL) {
            /* Case 2: One child (left) */
            temp = root;
            root = root->left;
            free(temp);
        }
        else {
            /* Case 3: Two children */
            temp = findMin(root->right);
            root->data = temp->data;
            root->right = deleteNode(root->right, temp->data);
        }
    }
    return root;
}

/* Function for Inorder Traversal (Left, Root, Right) */
void inorder(Node *root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

/* Menu-driven main function */
int main() {
    Node *root = NULL;
    int choice, value;

    while (1) {
        printf("\n--- Binary Search Tree Menu ---\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Inorder Traversal\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter value to insert: ");
            scanf("%d", &value);
            root = insert(root, value);
            break;
        case 2:
            printf("Enter value to delete: ");
            scanf("%d", &value);
            root = deleteNode(root, value);
            break;
        case 3:
            printf("Inorder Traversal: ");
            inorder(root);
            printf("\n");
            break;
        case 4:
            printf("Exiting...\n");
            exit(0);
        default:
            printf("Invalid choice! Try again.\n");
        }
    }
    return 0;
}
