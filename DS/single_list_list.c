#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
} SLL;

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

void InsertAtEnd(SLL **head, int value)
{
    SLL *newNode = CreateNode(value);
    if (!newNode)
    {

        return;
    }

    if (!(*head))
    {

        *head = newNode;
        return;
    }

    SLL *temp = *head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    temp->next = newNode;
}

void InsertAtBeginning(SLL **head, int value)
{
    SLL *newNode = CreateNode(value);
    if (!newNode)
    {

        return;
    }

    newNode->next = *head;
    *head = newNode;
}

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
            FreeList(list1);
            return 1;
        }
        InsertAtEnd(&list1, data);
    }

    PrintList(list1);

    FreeList(list1);

    return 0;
}