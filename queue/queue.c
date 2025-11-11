#include <stdio.h>
#include <stdlib.h>
#define SIZE 5

int queue[SIZE];
int front = -1, rear = -1;

int isFull() {
    return (rear == SIZE - 1);
}

int isEmpty() {
    return (front == -1 || front > rear);
}

void enqueueRear(int val) {
    if (isFull()) {
        printf("\nQueue is Full.\n");
        return;
    }
    if (front == -1) front = 0;
    queue[++rear] = val;
    printf("\nInserted %d at rear.\n", val);
}

void dequeueFront() {
    if (isEmpty()) {
        printf("\nQueue is Empty.\n");
        return;
    }
    printf("\nDeleted %d from front.\n", queue[front++]);
    if (front > rear) front = rear = -1; // reset when empty
}

void display() {
    int i;
    if (isEmpty()) {
        printf("\nQueue is Empty.\n");
        return;
    }
    printf("\nQueue Elements: ");
    for (i = front; i <= rear; i++)
        printf("%d ", queue[i]);
    printf("\n");
}

int main() {
    int choice, val;
    while (1) {
        printf("\n--- Basic Queue Menu ---\n");
        printf("1. Enqueue (Rear)\n");
        printf("2. Dequeue (Front)\n");
        printf("3. Display\n");
        printf("4. Check isEmpty\n");
        printf("5. Check isFull\n");
        printf("6. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &val);
                enqueueRear(val);
                break;
            case 2:
                dequeueFront();
                break;
            case 3:
                display();
                break;
            case 4:
                if (isEmpty()) printf("\nQueue is Empty.\n");
                else printf("\nQueue is not Empty.\n");
                break;
            case 5:
                if (isFull()) printf("\nQueue is Full.\n");
                else printf("\nQueue is not Full.\n");
                break;
            case 6:
                exit(0);
            default:
                printf("\nInvalid choice!\n");
        }
    }
    return 0;
}
