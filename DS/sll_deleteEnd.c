/*
 * Assignment No.: 02
 * Question No.: 1
 * Date: 11 July, 2025
 *
 * Program: Single Linked List Operations
 * Description: This program creates a single linked list
 * and performs the following operations

	1. Display list
	2. Insert at end
	3. Search an element
	4. Delete an element
	5. Sort in ascending order

 * Author: Biranchi Kulesika
 * Date: 15 July, 2025
 */

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

int SearchElement(SLL *head, int value)
{
	int position = 1;
	SLL *temp = head;
	while (temp != NULL)
	{
		if (temp->data == value)
			return position;
		temp = temp->next;
		position++;
	}
	return -1;
}

void DeleteElement(SLL **head, int value)
{
	if (*head == NULL)
	{
		printf("List is empty. Cannot delete.\n");
		return;
	}

	SLL *temp = *head, *prev = NULL;

	// If head node holds the value
	if (temp != NULL && temp->data == value)
	{
		*head = temp->next;
		free(temp);
		printf("Element %d deleted from the list.\n", value);
		return;
	}

	// Search for the value
	while (temp != NULL && temp->data != value)
	{
		prev = temp;
		temp = temp->next;
	}

	if (temp == NULL)
	{
		printf("Element %d not found in the list.\n", value);
		return;
	}

	prev->next = temp->next;
	free(temp);
	printf("Element %d deleted from the list.\n", value);
}

void SortListAscending(SLL **head)
{
	if (*head == NULL || (*head)->next == NULL)
		return;

	SLL *i, *j;
	int tempData;
	for (i = *head; i != NULL; i = i->next)
	{
		for (j = i->next; j != NULL; j = j->next)
		{
			if (i->data > j->data)
			{
				tempData = i->data;
				i->data = j->data;
				j->data = tempData;
			}
		}
	}
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

void DeleteAtEnd(SLL **head)
{
	// Case 1: The list is empty.
	if (*head == NULL)
	{
		printf("List is empty. Cannot delete.\n");
		return;
	}

	// Case 2: The list has only one node.
	if ((*head)->next == NULL)
	{
		printf("Deleted element %d from the end of the list.\n", (*head)->data);
		free(*head);
		*head = NULL;
		return;
	}

	SLL *temp = *head;
	while (temp->next->next != NULL)
	{
		temp = temp->next;
	}


	SLL *lastNode = temp->next;
	printf("Deleted element %d from the end of the list.\n", lastNode->data);

	// Unlink and free the last node.
	free(lastNode);
	temp->next = NULL;
}
