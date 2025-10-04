#include <stdio.h>
#include <stdlib.h>

// Defining the node structure
struct Node {
    int data;
    struct Node *next;
};

// Create a new node via DMA (Dynamic Memory Allocation)
struct Node* createNode(int x) {
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    if (!newNode) {
        printf("Error in memory allocation!\n");
        return NULL;
    }
    newNode->data = x;
    newNode->next = NULL;
    return newNode;
}

// Insert at the beginning of linked list
void insertAtBeginning(struct Node** head, int x) {
    struct Node* noder = createNode(x);
    noder->next = *head;
    *head = noder;
}

// Insert at the end of linked list
void insertAtEnd(struct Node** head, int x) {
    struct Node* newNode = createNode(x);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    struct Node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

// Insert at a specific position
void insertAtPosition(struct Node** head, int position, int x) {
    if (position == 0) {
        insertAtBeginning(head, x);
        return;
    }
    struct Node* newNode = createNode(x);
    struct Node* temp = *head;

    for (int i = 0; temp != NULL && i < position - 1; i++) {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Position does not exist\n");
        free(newNode);
        return;
    }

    newNode->next = temp->next;
    temp->next = newNode;
}

// Delete from beginning
void deleteFromBeginning(struct Node** head) {
    if (*head == NULL) {
        printf("List is empty\n");
        return;
    }
    struct Node* temp = *head;
    *head = (*head)->next;
    free(temp);
}

// Delete from end
void deleteFromEnd(struct Node** head) {
    if (*head == NULL) {
        printf("List is empty\n");
        return;
    }
    if ((*head)->next == NULL) {
        free(*head);
        *head = NULL;
        return;
    }
    struct Node* temp = *head;
    while (temp->next->next != NULL) {
        temp = temp->next;
    }
    free(temp->next);
    temp->next = NULL;
}

// Delete from specific position
void deleteFromPosition(struct Node** head, int position) {
    if (*head == NULL) {
        printf("List is empty\n");
        return;
    }
    struct Node* temp = *head;

    if (position == 0) {
        *head = temp->next;
        free(temp);
        return;
    }

    for (int i = 0; temp != NULL && i < position - 1; i++) {
        temp = temp->next;
    }

    if (temp == NULL || temp->next == NULL) {
        printf("Position does not exist\n");
        return;
    }

    struct Node* next = temp->next->next;
    free(temp->next);
    temp->next = next;
}

// Print linked list
void printLL(struct Node* head) {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Main function with examples
int main() {
    struct Node* head = NULL; // Initialize empty list

    printf("Inserting at beginning: 10\n");
    insertAtBeginning(&head, 10);
    printLL(head);

    printf("Inserting at end: 20\n");
    insertAtEnd(&head, 20);
    printLL(head);

    printf("Inserting at position 1: 15\n");
    insertAtPosition(&head, 1, 15); // Insert between 10 and 20
    printLL(head);

    printf("Deleting from beginning\n");
    deleteFromBeginning(&head);
    printLL(head);

    printf("Deleting from end\n");
    deleteFromEnd(&head);
    printLL(head);

    printf("Inserting more values\n");
    insertAtEnd(&head, 25);
    insertAtEnd(&head, 30);
    insertAtEnd(&head, 35);
    printLL(head);

    printf("Deleting from position 1\n");
    deleteFromPosition(&head, 1);
    printLL(head);

    return 0;
}
