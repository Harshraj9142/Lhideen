/*Write a menu driven program to implement a circular doubly linked list with the following operations:
i)     Insert any element in any given position (front, end or intermediate)
ii)    Delete an element from any given position (front, end or intermediate)
iii)   Display the list
iv)   Search
v)    Reverse the list*/

#include <stdio.h>
#include <stdlib.h>

/* Structure for Circular Doubly Linked List Node */
typedef struct Node {
    int data;
    struct Node *prev;
    struct Node *next;
} Node;

Node *head = NULL;

/* ---------------- INSERT OPERATIONS ---------------- */

/* 1. Insert at Front */
void insertAtFront(int value) {
    Node *newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        return;
    }
    newNode->data = value;

    if (head == NULL) {
        newNode->next = newNode;
        newNode->prev = newNode;
        head = newNode;
    } else {
        Node *tail = head->prev;
        newNode->next = head;
        newNode->prev = tail;
        tail->next = newNode;
        head->prev = newNode;
        head = newNode;
    }
    printf("%d inserted at the front.\n", value);
}

/* 2. Insert at End */
void insertAtEnd(int value) {
    Node *newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        return;
    }
    newNode->data = value;

    if (head == NULL) {
        newNode->next = newNode;
        newNode->prev = newNode;
        head = newNode;
    } else {
        Node *tail = head->prev;
        newNode->next = head;
        newNode->prev = tail;
        tail->next = newNode;
        head->prev = newNode;
    }
    printf("%d inserted at the end.\n", value);
}

/* 3. Insert at a specific position */
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

    if (temp->next == head) {  /* inserting at end */
        insertAtEnd(value);
        free(newNode);
        return;
    }

    newNode->next = temp->next;
    newNode->prev = temp;
    temp->next->prev = newNode;
    temp->next = newNode;

    printf("%d inserted at position %d.\n", value, pos);
}

/* ---------------- DELETE OPERATIONS ---------------- */

/* 4. Delete from Front */
void deleteFromFront() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    Node *temp = head;
    if (head->next == head) {
        printf("Deleted element: %d\n", temp->data);
        free(temp);
        head = NULL;
    } else {
        Node *tail = head->prev;
        printf("Deleted element: %d\n", head->data);
        head = head->next;
        tail->next = head;
        head->prev = tail;
        free(temp);
    }
}

/* 5. Delete from End */
void deleteFromEnd() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    Node *tail = head->prev;

    if (head->next == head) {
        printf("Deleted element: %d\n", head->data);
        free(head);
        head = NULL;
        return;
    }

    printf("Deleted element: %d\n", tail->data);
    tail->prev->next = head;
    head->prev = tail->prev;
    free(tail);
}

/* 6. Delete from a given position */
void deleteFromPosition(int pos) {
    int i;
    Node *temp = head;

    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    if (pos <= 1) {
        deleteFromFront();
        return;
    }

    for (i = 1; i < pos && temp->next != head; i++)
        temp = temp->next;

    if (temp == head) {
        printf("Invalid position.\n");
        return;
    }

    printf("Deleted element: %d\n", temp->data);
    temp->prev->next = temp->next;
    temp->next->prev = temp->prev;

    if (temp == head)
        head = head->next;

    free(temp);
}

/* ---------------- DISPLAY, SEARCH, REVERSE ---------------- */

/* 7. Display the list */
void display() {
    Node *temp = head;

    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    printf("Circular Doubly Linked List: ");
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("\n");
}

/* 8. Search an element */
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

/* 9. Reverse the list */
void reverse() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    Node *current = head;
    Node *temp = NULL;

    do {
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;
        current = current->prev;
    } while (current != head);

    if (temp != NULL)
        head = temp->prev;

    printf("List reversed successfully.\n");
}

/* ---------------- MENU DRIVER ---------------- */
int main() {
    int choice, value, pos;

    while (1) {
        printf("\n--- Circular Doubly Linked List Menu ---\n");
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
