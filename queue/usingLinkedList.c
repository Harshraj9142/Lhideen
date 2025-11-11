#include <stdio.h>
#include <stdlib.h>

/* Define structure for a queue node */
typedef struct Node {
    int data;
    struct Node *next;
} Node;

Node *front = NULL;  /* Points to the front of the queue */
Node *rear = NULL;   /* Points to the rear of the queue */

/* Function to add an element to the queue (Enqueue) */
void enqueue(int value) {
    Node *newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        return;
    }

    newNode->data = value;
    newNode->next = NULL;

    if (rear == NULL) {
        /* If queue is empty, both front and rear point to newNode */
        front = rear = newNode;
    } else {
        rear->next = newNode;
        rear = newNode;
    }

    printf("%d enqueued successfully.\n", value);
}

/* Function to remove an element from the queue (Dequeue) */
void dequeue() {
    if (front == NULL) {
        printf("Queue Underflow! Cannot dequeue from empty queue.\n");
        return;
    }

    Node *temp = front;
    printf("Dequeued element: %d\n", front->data);

    front = front->next;  /* Move front to the next node */
    free(temp);            /* Free memory of dequeued node */

    if (front == NULL) {
        /* If queue becomes empty, reset rear to NULL */
        rear = NULL;
    }
}

/* Function to check if the queue is empty */
void isEmpty() {
    if (front == NULL)
        printf("Queue is empty.\n");
    else
        printf("Queue is not empty.\n");
}

/* Function to display the queue elements */
void display() {
    Node *temp = front;
    if (temp == NULL) {
        printf("Queue is empty.\n");
        return;
    }

    printf("Queue elements (Front to Rear): ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

/* Main menu-driven function */
int main() {
    int choice, value;

    while (1) {
        printf("\n--- Queue Using Singly Linked List ---\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. isEmpty\n");
        printf("4. Display\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter value to enqueue: ");
            scanf("%d", &value);
            enqueue(value);
            break;

        case 2:
            dequeue();
            break;

        case 3:
            isEmpty();
            break;

        case 4:
            display();
            break;

        case 5:
            printf("Exiting...\n");
            exit(0);

        default:
            printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}
