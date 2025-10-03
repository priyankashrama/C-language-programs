#include <stdio.h>
#include <stdlib.h>

// Stack implemented via linked list

// Node structure
struct Node {
    int data;
    struct Node *next;
};

// Create a new node via DMA
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

// Push element onto stack (insert at beginning)
void push(struct Node** head, int x) {
    struct Node* noder = createNode(x);
    noder->next = *head;
    *head = noder;
    printf("Pushed: %d\n", x);
}

// Pop element from stack (delete from beginning)
void pop(struct Node** head) {
    if (*head == NULL) {
        printf("Stack is empty\n");
        return;
    }
    struct Node* temp = *head;
    *head = (*head)->next;
    printf("Popped: %d\n", temp->data);
    free(temp);
}

// Peek at top element of stack
void peek(struct Node* head) {
    if (head == NULL) {
        printf("Stack is empty\n");
        return;
    }
    printf("Top element: %d\n", head->data);
}

// Print stack
void printStack(struct Node* head) {
    if (head == NULL) {
        printf("Stack is empty\n");
        return;
    }
    printf("Stack: ");
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Main function
int main() {
    struct Node* stack = NULL; // Initialize empty stack

    push(&stack, 10);
    printStack(stack);

    push(&stack, 16);
    printStack(stack);

    push(&stack, 61);
    printStack(stack);

    peek(stack);

    pop(&stack);
    printStack(stack);

    push(&stack, 85);
    printStack(stack);

    peek(stack);

    pop(&stack);
    printStack(stack);

    pop(&stack);
    printStack(stack);

    pop(&stack); // popping from empty stack
    printStack(stack);

    return 0;
}
