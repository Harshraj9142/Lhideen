#include <stdio.h>
#include <stdlib.h>
#define SIZE 5

int queue[SIZE];
int front = -1, rear = -1;

int isFull() {
    return ((rear + 1) % SIZE == front);
}

int isEmpty() {
    return (front == -1);
}

void enqueueRear(int val) {
    if (isFull()) {
        printf("\nQueue is Full.\n");
        return;
    }
    if (front == -1) front = 0;
    rear = (rear + 1) % SIZE;
    queue[rear] = val;
    printf("\nInserted %d at rear.\n", val);
}

void dequeueFront() {
    int val;
    if (isEmpty()) {
        printf("\nQueue is Empty.\n");
        return;
    }
    val = queue[front];
    if (front == rear) { // only one element
        front = rear = -1;
    } else {
        front = (front + 1) % SIZE;
    }
    printf("\nDeleted %d from front.\n", val);
}

void display() {
    int i;
    if (isEmpty()) {
        printf("\nQueue is Empty.\n");
        return;
    }
    printf("\nQueue Elements: ");
    i = front;
    while (1) {
        printf("%d ", queue[i]);
        if (i == rear) break;
        i = (i + 1) % SIZE;
    }
    printf("\n");
}

int main() {
    int choice, val;
    while (1) {
        printf("\n--- Circular Queue Menu ---\n");
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
