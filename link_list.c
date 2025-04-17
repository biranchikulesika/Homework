#include <stdio.h>
#include <stdlib.h>

// Define the structure for a singly linked list node
typedef struct Node
{
    int data;
    struct Node *next;
} SLL;

// Function to create a new node
SLL *CreateNode(int value)
{
    SLL *newNode = (SLL *)malloc(sizeof(SLL));
    if (!newNode)
    {
        printf("Error: Memory allocation failed in CreateNode.\n");
        return NULL;
    }
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a node at the end of the list
SLL *InsertAtEnd(SLL *head, int value)
{
    SLL *newNode = CreateNode(value);
    if (newNode == NULL)
    {
        return head; // Return the unchanged list if memory allocation fails
    }

    if (head == NULL)
    {
        return newNode; // If the list is empty, the new node becomes the head
    }

    SLL *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newNode;
    return head;
}

SLL *InsertAtBeginning(SLL *head, int value)
{
    SLL *newNode = CreateNode(value);
    if (newNode == NULL)
    {
        return head; // Return the unchanged list if memory allocation fails
    }

    newNode->next = head; // Point the new node to the current head
    return newNode;       // The new node becomes the new head
}

// Function to print the linked list
void PrintList(SLL *head)
{
    if (head == NULL)
    {
        printf("List is empty.\n");
        return;
    }

    SLL *temp = head;
    while (temp != NULL)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Function to free all nodes in the linked list
void FreeList(SLL *head)
{
    SLL *temp;
    while (head != NULL)
    {
        temp = head->next;
        free(head);
        head = temp;
    }
}

// Main function
int main()
{
    int n, data;

    printf("Enter the number of elements: ");
    if (scanf("%d", &n) != 1 || n < 0)
    {
        printf("Invalid input. Exiting.\n");
        return 1;
    }

    SLL *list1 = NULL;

    for (int i = 0; i < n; i++)
    {
        printf("Enter the data: ");
        if (scanf("%d", &data) != 1)
        {
            printf("Invalid input. Exiting.\n");
            FreeList(list1); // Free any allocated memory before exiting
            return 1;
        }
        list1 = InsertAtEnd(list1, data);
    }

    PrintList(list1);

    FreeList(list1);

    return 0;
}