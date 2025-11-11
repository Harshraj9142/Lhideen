#include <stdio.h>
#include <stdlib.h>

/* Define structure for a node in the stack */
typedef struct Node {
    int data;
    struct Node *next;
} Node;

Node *top = NULL; /* Initialize top pointer as NULL */

/* Function to push an element onto the stack */
void push(int value) {
    Node *newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        return;
    }
    newNode->data = value;
    newNode->next = top; /* Link new node to the previous top */
    top = newNode;       /* Update top pointer */
    printf("%d pushed onto the stack.\n", value);
}

/* Function to pop an element from the stack */
void pop() {
    if (top == NULL) {
        printf("Stack Underflow! Cannot pop from empty stack.\n");
        return;
    }

    Node *temp = top;
    printf("Popped element: %d\n", top->data);
    top = top->next;  /* Move top pointer to next node */
    free(temp);       /* Free memory of popped node */
}

/* Function to return top element without removing it (peek) */
void peek() {
    if (top == NULL) {
        printf("Stack is empty.\n");
    } else {
        printf("Top element: %d\n", top->data);
    }
}

/* Function to check if stack is empty */
void isEmpty() {
    if (top == NULL)
        printf("Stack is empty.\n");
    else
        printf("Stack is not empty.\n");
}

/* Function to display stack elements */
void display() {
    Node *temp = top;
    if (temp == NULL) {
        printf("Stack is empty.\n");
        return;
    }

    printf("Stack elements (Top to Bottom): ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

/* Main menu-driven program */
int main() {
    int choice, value;

    while (1) {
        printf("\n--- Stack Using Singly Linked List ---\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Peek\n");
        printf("4. isEmpty\n");
        printf("5. Display\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter value to push: ");
            scanf("%d", &value);
            push(value);
            break;

        case 2:
            pop();
            break;

        case 3:
            peek();
            break;

        case 4:
            isEmpty();
            break;

        case 5:
            display();
            break;

        case 6:
            printf("Exiting...\n");
            exit(0);

        default:
            printf("Invalid choice! Try again.\n");
        }
    }
    return 0;
}
