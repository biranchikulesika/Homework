/*
 * Program: Merge Two Sorted Linked Lists
 * Description: This C program defines two sorted linked lists and merges them
 *              into a single sorted linked list.
 *
 * Author: Biranchi Kulesika
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
} SLL;

SLL *createNode(int data)
{
    SLL *newNode = (SLL *)malloc(sizeof(SLL));
    if (newNode == NULL)
    {
        printf("Error: Memory allocation failed.\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void insertAtEnd(SLL **head, int data)
{
    SLL *newNode = createNode(data);
    if (*head == NULL)
    {
        *head = newNode;
        return;
    }
    SLL *last = *head;
    while (last->next != NULL)
    {
        last = last->next;
    }
    last->next = newNode;
}

/**
 * @brief Merges two sorted linked lists into a single sorted list.
 *
 * @param list1 The head of the first sorted list.
 * @param list2 The head of the second sorted list.
 * @return The head of the new merged sorted list.
 */
SLL *mergeSortedLists(SLL *list1, SLL *list2)
{
    // Create a dummy node to simplify the merge logic
    SLL dummy;
    SLL *tail = &dummy;
    dummy.next = NULL;

    // Traverse both lists and append the smaller node to the result
    while (list1 != NULL && list2 != NULL)
    {
        if (list1->data <= list2->data)
        {
            tail->next = list1;
            list1 = list1->next;
        }
        else
        {
            tail->next = list2;
            list2 = list2->next;
        }
        tail = tail->next;
    }

    // Append the remaining nodes from the non-empty list
    if (list1 != NULL)
    {
        tail->next = list1;
    }
    else
    {
        tail->next = list2;
    }

    return dummy.next;
}

/**
 * @brief Prints the elements of a linked list.
 *
 * @param node The head of the list to print.
 */
void printList(SLL *node)
{
    while (node != NULL)
    {
        printf("%d -> ", node->data);
        node = node->next;
    }
    printf("NULL\n");
}

int main()
{
    // Create two sorted linked lists
    SLL *list1 = NULL;
    insertAtEnd(&list1, 5);
    insertAtEnd(&list1, 10);
    insertAtEnd(&list1, 15);

    SLL *list2 = NULL;
    insertAtEnd(&list2, 2);
    insertAtEnd(&list2, 3);
    insertAtEnd(&list2, 20);

    printf("List 1: ");
    printList(list1);

    printf("List 2: ");
    printList(list2);

    // Merge the two lists
    SLL *mergedList = mergeSortedLists(list1, list2);

    printf("\nMerged Sorted List: ");
    printList(mergedList);

    // Note: No need to free list1 and list2 separately as their nodes are now part of mergedList.
    // Freeing mergedList will deallocate all nodes.
    free(mergedList);

    return 0;
}
