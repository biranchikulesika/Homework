/*
 * Program: Insert at any position in Singly Linked List
 * Description: This C program demonstrates how to insert a node at any given position in a singly linked list.
 *              It includes functions to create a list, print it, insert at a specific position,
 *              and free the allocated memory.
 *
 * Author: Gemini Code Assist
 */

#include <stdio.h>
#include <stdlib.h>

// Define the structure for a node in the linked list
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
		exit(EXIT_FAILURE);
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

void insertAtPosition(SLL **head, int data, int pos)
{
	SLL *newNode = createNode(data);

	if (pos == 1)
	{
		newNode->next = *head;
		*head = newNode;
		return;
	}

	SLL *temp = *head;
	SLL *prev = NULL;
	int count = 1;

	while (temp != NULL && count < pos)
	{
		prev = temp;
		temp = temp->next;
		count++;
	}

	if (count == pos)
	{
		newNode->next = temp;
		if (prev != NULL)
		{
			prev->next = newNode;
		}
		else
		{
			*head = newNode;
		}
	}
	else
	{
		printf("pos is out of range.\n");
		free(newNode); // Free the allocated memory because insertion failed
	}
}

void printList(SLL *head)
{
	while (head != NULL)
	{
		printf("%d -> ", head->data);
		head = head->next;
	}
	printf("NULL\n");
}

int main()
{
	SLL *head = NULL;

	// Build a sample list: 1 -> 2 -> 3 -> 4 -> 5
	insertAtEnd(&head, 1);
	insertAtEnd(&head, 2);
	insertAtEnd(&head, 3);
	insertAtEnd(&head, 4);
	insertAtEnd(&head, 5);

	printf("Original list:\n");
	printList(head);

	// Insert a new node with data 10 at pos 3
	insertAtPosition(&head, 10, 3);

	printf("\nList after inserting 10 at position 3:\n");
	printList(head);

	// Insert a new node with data 20 at position 1
	insertAtPosition(&head, 20, 1);

	printf("\nList after inserting 20 at position 1:\n");
	printList(head);

	return 0;
}