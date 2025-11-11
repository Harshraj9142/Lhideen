/*Write a menu driven program to implement a circular singly linked list with the operations:
i)     Insert any element in any given position (front, end or intermediate)
ii)    Delete an element from any given position (front, end or intermediate)
iii)   Display the list
iv)   Search
v)    Reverse the list*/

#include <stdio.h>
#include <stdlib.h>

/* Node structure */
typedef struct Node {
    int data;
    struct Node *next;
} Node;

Node *head = NULL;  /* Start pointer */

/* 1. Insert at front */
void insertAtFront(int value) {
    Node *newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        return;
    }
    newNode->data = value;

    if (head == NULL) {
        head = newNode;
        newNode->next = head;  /* Points to itself */
    } else {
        Node *temp = head;
        while (temp->next != head)
            temp = temp->next;
        temp->next = newNode;
        newNode->next = head;
        head = newNode;
    }
    printf("%d inserted at the front.\n", value);
}

/* 2. Insert at end */
void insertAtEnd(int value) {
    Node *newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        return;
    }
    newNode->data = value;

    if (head == NULL) {
        head = newNode;
        newNode->next = head;
    } else {
        Node *temp = head;
        while (temp->next != head)
            temp = temp->next;
        temp->next = newNode;
        newNode->next = head;
    }
    printf("%d inserted at the end.\n", value);
}

/* 3. Insert at given position */
void insertAtPosition(int value, int pos) {
    int i;
    Node *newNode, *temp;

    newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        return;
    }

    newNode->data = value;

    if (head == NULL || pos <= 1) {
        insertAtFront(value);
        free(newNode);
        return;
    }

    temp = head;
    for (i = 1; i < pos - 1 && temp->next != head; i++)
        temp = temp->next;

    newNode->next = temp->next;
    temp->next = newNode;
    printf("%d inserted at position %d.\n", value, pos);
}

/* 4. Delete from front */
void deleteFromFront() {
    Node *temp, *last;
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    if (head->next == head) {
        printf("Deleted element: %d\n", head->data);
        free(head);
        head = NULL;
        return;
    }

    temp = head;
    last = head;
    while (last->next != head)
        last = last->next;

    printf("Deleted element: %d\n", head->data);
    head = head->next;
    last->next = head;
    free(temp);
}

/* 5. Delete from end */
void deleteFromEnd() {
    Node *temp, *prev;

    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    if (head->next == head) {
        printf("Deleted element: %d\n", head->data);
        free(head);
        head = NULL;
        return;
    }

    temp = head;
    while (temp->next != head) {
        prev = temp;
        temp = temp->next;
    }

    printf("Deleted element: %d\n", temp->data);
    prev->next = head;
    free(temp);
}

/* 6. Delete from a given position */
void deleteFromPosition(int pos) {
    Node *temp = head, *prev;
    int i;

    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    if (pos <= 1) {
        deleteFromFront();
        return;
    }

    for (i = 1; i < pos && temp->next != head; i++) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == head) {
        printf("Invalid position.\n");
        return;
    }

    prev->next = temp->next;
    printf("Deleted element: %d\n", temp->data);
    free(temp);
}

/* 7. Display the circular linked list */
void display() {
    Node *temp = head;
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    printf("Circular Linked List: ");
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("\n");
}

/* 8. Search for an element */
void search(int value) {
    Node *temp = head;
    int pos = 1;

    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    do {
        if (temp->data == value) {
            printf("%d found at position %d.\n", value, pos);
            return;
        }
        temp = temp->next;
        pos++;
    } while (temp != head);

    printf("%d not found in the list.\n", value);
}

/* 9. Reverse the circular singly linked list */
void reverse() {
    if (head == NULL || head->next == head) {
        printf("List reversed successfully (only one element).\n");
        return;
    }

    Node *prev = NULL, *current = head, *nextNode;
    Node *last = head;

    /* find last node */
    while (last->next != head)
        last = last->next;

    do {
        nextNode = current->next;
        current->next = prev ? prev : last;
        prev = current;
        current = nextNode;
    } while (current != head);

    head = prev;
    printf("List reversed successfully.\n");
}

/* ---------------- MENU ---------------- */
int main() {
    int choice, value, pos;

    while (1) {
        printf("\n--- Circular Singly Linked List Menu ---\n");
        printf("1. Insert at Front\n");
        printf("2. Insert at End\n");
        printf("3. Insert at Position\n");
        printf("4. Delete from Front\n");
        printf("5. Delete from End\n");
        printf("6. Delete from Position\n");
        printf("7. Display\n");
        printf("8. Search\n");
        printf("9. Reverse\n");
        printf("10. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter value: ");
            scanf("%d", &value);
            insertAtFront(value);
            break;
        case 2:
            printf("Enter value: ");
            scanf("%d", &value);
            insertAtEnd(value);
            break;
        case 3:
            printf("Enter value and position: ");
            scanf("%d %d", &value, &pos);
            insertAtPosition(value, pos);
            break;
        case 4:
            deleteFromFront();
            break;
        case 5:
            deleteFromEnd();
            break;
        case 6:
            printf("Enter position: ");
            scanf("%d", &pos);
            deleteFromPosition(pos);
            break;
        case 7:
            display();
            break;
        case 8:
            printf("Enter value to search: ");
            scanf("%d", &value);
            search(value);
            break;
        case 9:
            reverse();
            break;
        case 10:
            printf("Exiting...\n");
            exit(0);
        default:
            printf("Invalid choice! Try again.\n");
        }
    }

    return 0;
}
