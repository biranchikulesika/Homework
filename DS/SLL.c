#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} SLL;

void insertEnd(SLL** head, int value) {
    SLL* newNode = (SLL*) malloc(sizeof(SLL));
    newNode->data = value;
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
        return;
    }

    SLL* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

// Function to display the list
void displayList(SLL* head) {
    SLL* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Function to search and delete using double pointer
void searchAndDelete(SLL** head, int key) {
    SLL* temp = *head;
    SLL* prev = NULL;

    while (temp != NULL && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Node with value %d not found.\n", key);
        return;
    }

    if (prev == NULL) {
        // Node to be deleted is head
        *head = temp->next;
    } else {
        prev->next = temp->next;
    }

    free(temp);
    printf("Node with value %d deleted.\n", key);
}

// Main function
int main() {
    SLL* head = NULL;
    int n, value, key, i;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    printf("Enter the values:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &value);
        insertEnd(&head, value);
    }

    printf("Original list:\n");
    displayList(head);

    printf("Enter value to search and delete: ");
    scanf("%d", &key);

    searchAndDelete(&head, key);

    printf("Updated list:\n");
    displayList(head);

    return 0;
}
