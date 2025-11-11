/*
Write a menu driven program to implement a Doubly Linked List with the following operations:
i)     Insert any element in any given position (front, end or intermediate)
ii)    Delete an element from any given position (front, end, intermediate)                                                     
iii)   Display the list
iv)   Search
v)    Reverse the list
*/

#include <stdio.h>
#include <stdlib.h>

/* Define structure for Doubly Linked List node */
typedef struct Node {
    int data;
    struct Node *prev;
    struct Node *next;
} Node;

Node *head = NULL;  /* Points to the first node */
Node *tail = NULL;  /* Points to the last node */

/* 1. Insert at front */
void insertAtFront(int value) {
    Node *newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        return;
    }

    newNode->data = value;
    newNode->prev = NULL;
    newNode->next = head;

    if (head != NULL)
        head->prev = newNode;
    else
        tail = newNode; /* First node */

    head = newNode;
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
    newNode->next = NULL;
    newNode->prev = tail;

    if (tail != NULL)
        tail->next = newNode;
    else
        head = newNode; /* First node */

    tail = newNode;
    printf("%d inserted at the end.\n", value);
}

/* 3. Insert at given position */
void insertAtPosition(int value, int pos) {
    Node *newNode, *temp;
    int i;

    newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        return;
    }

    newNode->data = value;
    newNode->prev = NULL;
    newNode->next = NULL;

    if (pos <= 1 || head == NULL) {
        insertAtFront(value);
        free(newNode); /* Because insertAtFront allocates its own */
        return;
    }

    temp = head;
    for (i = 1; i < pos - 1 && temp->next != NULL; i++)
        temp = temp->next;

    if (temp->next == NULL) {
        insertAtEnd(value);
        free(newNode); /* Because insertAtEnd allocates its own */
        return;
    }

    newNode->next = temp->next;
    newNode->prev = temp;
    temp->next->prev = newNode;
    temp->next = newNode;

    printf("%d inserted at position %d.\n", value, pos);
}

/* 4. Delete from front */
void deleteFromFront() {
    Node *temp;

    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    temp = head;
    printf("Deleted element: %d\n", temp->data);

    head = head->next;
    if (head != NULL)
        head->prev = NULL;
    else
        tail = NULL; /* List became empty */

    free(temp);
}

/* 5. Delete from end */
void deleteFromEnd() {
    Node *temp;

    if (tail == NULL) {
        printf("List is empty.\n");
        return;
    }

    temp = tail;
    printf("Deleted element: %d\n", temp->data);

    tail = tail->prev;
    if (tail != NULL)
        tail->next = NULL;
    else
        head = NULL; /* List became empty */

    free(temp);
}

/* 6. Delete from a given position */
void deleteFromPosition(int pos) {
    Node *temp;
    int i;

    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    if (pos <= 1) {
        deleteFromFront();
        return;
    }

    temp = head;
    for (i = 1; i < pos && temp != NULL; i++)
        temp = temp->next;

    if (temp == NULL) {
        printf("Invalid position.\n");
        return;
    }

    if (temp->prev != NULL)
        temp->prev->next = temp->next;

    if (temp->next != NULL)
        temp->next->prev = temp->prev;

    if (temp == head)
        head = temp->next;

    if (temp == tail)
        tail = temp->prev;

    printf("Deleted element: %d\n", temp->data);
    free(temp);
}

/* 7. Display list (forward) */
void display() {
    Node *temp = head;
    if (temp == NULL) {
        printf("List is empty.\n");
        return;
    }

    printf("Doubly Linked List (Front to End): ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

/* 8. Search for an element */
void search(int value) {
    Node *temp = head;
    int pos = 1;

    while (temp != NULL) {
        if (temp->data == value) {
            printf("%d found at position %d.\n", value, pos);
            return;
        }
        temp = temp->next;
        pos++;
    }
    printf("%d not found in the list.\n", value);
}

/* 9. Reverse the list */
void reverse() {
    Node *current = head;
    Node *temp = NULL;

    while (current != NULL) {
        /* Swap next and prev */
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;
        current = current->prev; /* Move to next node (which is prev now) */
    }

    /* Swap head and tail */
    if (temp != NULL)
        head = temp->prev;

    printf("List reversed successfully.\n");
}

/* Main menu */
int main() {
    int choice, value, pos;

    while (1) {
        printf("\n--- Doubly Linked List Menu ---\n");
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
