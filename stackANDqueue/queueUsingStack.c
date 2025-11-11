#include <stdio.h>
#include <stdlib.h>

#define SIZE 5   /* Maximum size of stack */

/* Global stacks */
int stack1[SIZE];
int stack2[SIZE];
int top1 = -1;
int top2 = -1;

/* Function to push an element onto a stack */
void push1(int value) {
    if (top1 == SIZE - 1) {
        printf("Stack Overflow (Stack1)\n");
        return;
    }
    top1++;
    stack1[top1] = value;
}

void push2(int value) {
    if (top2 == SIZE - 1) {
        printf("Stack Overflow (Stack2)\n");
        return;
    }
    top2++;
    stack2[top2] = value;
}

/* Function to pop an element from a stack */
int pop1() {
    if (top1 == -1) {
        printf("Stack Underflow (Stack1)\n");
        return -1;
    }
    return stack1[top1--];
}

int pop2() {
    if (top2 == -1) {
        printf("Stack Underflow (Stack2)\n");
        return -1;
    }
    return stack2[top2--];
}

/* Enqueue operation using Stack1 */
void enqueue(int value) {
    if (top1 == SIZE - 1) {
        printf("Queue Overflow\n");
        return;
    }
    push1(value);
    printf("Enqueued %d successfully.\n", value);
}

/* Dequeue operation using both stacks */
void dequeue() {
    int x;
    if (top1 == -1 && top2 == -1) {
        printf("Queue Underflow\n");
        return;
    }

    /* Move all elements from Stack1 to Stack2 if Stack2 is empty */
    if (top2 == -1) {
        while (top1 != -1) {
            x = pop1();
            push2(x);
        }
    }

    x = pop2();
    printf("Dequeued element: %d\n", x);
}

/* Display queue elements */
void display() {
    int i;

    if (top1 == -1 && top2 == -1) {
        printf("Queue is empty.\n");
        return;
    }

    printf("Queue elements (front to rear): ");

    /* Display elements in stack2 (front side) */
    for (i = top2; i >= 0; i--) {
        printf("%d ", stack2[i]);
    }

    /* Display elements in stack1 (rear side) */
    for (i = 0; i <= top1; i++) {
        printf("%d ", stack1[i]);
    }
    printf("\n");
}

/* Menu-driven main function */
int main() {
    int choice, value;

    while (1) {
        printf("\n--- Queue Using Two Stacks ---\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Exit\n");
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
            display();
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
