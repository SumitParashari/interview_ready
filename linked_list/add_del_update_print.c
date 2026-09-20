#include <stdio.h>
#include <stdlib.h>

// TODO: Make it library to add, del, update, print
typedef struct linked_list NODE;
struct linked_list {
    int data;
    NODE *next;
};

void insertAtHead(struct Node** head_ref, int new_data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = new_data;
    
    new_node->next = (*head_ref); // Point new node to the old head
    *head_ref = new_node;         // Move head to point to the new node
}

void insertAtTail(struct Node** head_ref, int new_data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    struct Node* last = *head_ref;
    
    new_node->data = new_data;
    new_node->next = NULL; // This will be the last node, so next is NULL

    // If the Linked List is empty, make the new node the head
    if (*head_ref == NULL) {
        *head_ref = new_node;
        return;
    }

    // Otherwise, traverse until the last node
    while (last->next != NULL) {
        last = last->next;
    }

    last->next = new_node; // Change the next of the last node
}

void insertAfterNode(struct Node* prev_node, int new_data) {
    // Check if the given prev_node is NULL
    if (prev_node == NULL) {
        printf("The given previous node cannot be NULL.\n");
        return;
    }

    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = new_data;

    new_node->next = prev_node->next; // Point new node to the next of prev_node
    prev_node->next = new_node;       // Point prev_node to the new node
}


int deleteNodeByKey(NODE **head_ref, int key) {
    // Store head node
    struct Node* temp = *head_ref;
    struct Node* prev = NULL;

    // CASE 1: If the head node itself holds the key to be deleted
    if (temp != NULL && temp->data == key) {
        *head_ref = temp->next; // Changed head
        free(temp);             // free old head
        return 0;
    }

    // CASE 2: Search for the key to be deleted, keep track of the
    // previous node as we need to change 'prev->next'
    while (temp != NULL && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }

    // If key was not present in linked list
    if (temp == NULL) return -1;

    // Unlink the node from linked list
    prev->next = temp->next;

    // Free memory
    free(temp);
    return 0;
}

void deleteNodeAtPosition(NODE **head_ref, int position) {
    // Case 1: If the linked list is empty
    if (*head_ref == NULL) {
        printf("List is empty. Deletion not possible.\n");
        return;
    }

    struct Node* temp = *head_ref;

    // Case 2: If the head node itself needs to be deleted
    if (position == 0) {
        *head_ref = temp->next; // Move head to the next node
        free(temp);             // Free the old head memory
        return;
    }

    // Case 3: Traverse to find the node just BEFORE the one to be deleted
    for (int i = 0; temp != NULL && i < position - 1; i++) {
        temp = temp->next;
    }

    // If the position is out of bounds (e.g., position > length of list)
    if (temp == NULL || temp->next == NULL) {
        printf("Position %d is out of bounds.\n", position);
        return;
    }

    // temp->next is the node to be deleted
    struct Node* next_node = temp->next->next; // Store pointer to the node after the target node

    free(temp->next); // Free the memory of the target node

    temp->next = next_node; // Unlink the deleted node from the list
}


void printList(NODE *head) {
    while(head =! NULL) {
        printf("-> %d, ", head->data);
        head = head->next;
    }
    printf("\n");
}

