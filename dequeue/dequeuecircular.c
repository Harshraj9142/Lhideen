/*
2. Write a menu driven program to implement a dequeue using array (Circular array) with the following operations-
i. enqueueRear
ii. enqueueFront
iii. dequeueRear
iv. dequeueFront
v. isEmpty
vi. isFull*/

#include <stdio.h>
#include <stdlib.h>
#define SIZE 5

int deque[SIZE];
int front = -1, rear = -1;

int isFull() {
    return ((front == 0 && rear == SIZE - 1) || (front == rear + 1));
}

int isEmpty() {
    return (front == -1);
}

void enqueueFront(int val) {
    if (isFull()) {
        printf("\nDeque is Full.\n");
        return;
    }
    if (front == -1) {
        front = rear = 0;
    } else if (front == 0) {
        front = SIZE - 1;
    } else {
        front--;
    }
    deque[front] = val;
    printf("\nInserted %d at front.\n", val);
}

void enqueueRear(int val) {
    if (isFull()) {
        printf("\nDeque is Full.\n");
        return;
    }
    if (front == -1) {
        front = rear = 0;
    } else if (rear == SIZE - 1) {
        rear = 0;
    } else {
        rear++;
    }
    deque[rear] = val;
    printf("\nInserted %d at rear.\n", val);
}

void dequeueFront() {
    if (isEmpty()) {
        printf("\nDeque is Empty.\n");
        return;
    }
    printf("\nDeleted %d from front.\n", deque[front]);
    if (front == rear) {
        front = rear = -1;
    } else if (front == SIZE - 1) {
        front = 0;
    } else {
        front++;
    }
}

void dequeueRear() {
    if (isEmpty()) {
        printf("\nDeque is Empty.\n");
        return;
    }
    printf("\nDeleted %d from rear.\n", deque[rear]);
    if (front == rear) {
        front = rear = -1;
    } else if (rear == 0) {
        rear = SIZE - 1;
    } else {
        rear--;
    }
}

void display() {
    int i;
    if (isEmpty()) {
        printf("\nDeque is Empty.\n");
        return;
    }
    printf("\nDeque Elements: ");
    i = front;
    while (1) {
        printf("%d ", deque[i]);
        if (i == rear) break;
        i = (i + 1) % SIZE;
    }
    printf("\n");
}

int main() {
    int choice, val;
    while (1) {
        printf("\n--- Circular Deque Menu ---\n");
        printf("1. Enqueue Front\n");
        printf("2. Enqueue Rear\n");
        printf("3. Dequeue Front\n");
        printf("4. Dequeue Rear\n");
        printf("5. Display\n");
        printf("6. Check isEmpty\n");
        printf("7. Check isFull\n");
        printf("8. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &val);
                enqueueFront(val);
                break;
            case 2:
                printf("Enter value: ");
                scanf("%d", &val);
                enqueueRear(val);
                break;
            case 3:
                dequeueFront();
                break;
            case 4:
                dequeueRear();
                break;
            case 5:
                display();
                break;
            case 6:
                if (isEmpty()) printf("\nDeque is Empty.\n");
                else printf("\nDeque is not Empty.\n");
                break;
            case 7:
                if (isFull()) printf("\nDeque is Full.\n");
                else printf("\nDeque is not Full.\n");
                break;
            case 8:
                exit(0);
            default:
                printf("\nInvalid choice!\n");
        }
    }
    return 0;
}
