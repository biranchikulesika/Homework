/*
 * Program: Reverse a Singly Linked List
 * Description: This C program demonstrates how to reverse a singly linked list.
 *              It includes functions to create a list, print it, reverse it,
 *              and free the allocated memory.
 *
 * Author: Gemini Code Assist
 */

#include <stdio.h>
#include <stdlib.h>

// Define the structure for a SLL in the linked list
typedef struct Node
{
	int data;
	struct Node *next;
} SLL;


SLL *createSLL(int data)
{
	SLL *newSLL = (SLL *)malloc(sizeof(SLL));
	if (newSLL == NULL)
	{
		printf("Error: Memory allocation failed.\n");
		exit(EXIT_FAILURE);
	}
	newSLL->data = data;
	newSLL->next = NULL;
	return newSLL;
}

void insertAtEnd(SLL **head, int data)
{
	SLL *newSLL = createSLL(data);
	if (*head == NULL)
	{
		*head = newSLL;
		return;
	}
	SLL *last = *head;
	while (last->next != NULL)
	{
		last = last->next;
	}
	last->next = newSLL;
}

void reverseList(SLL **head)
{
	SLL *prev = NULL;
	SLL *current = *head;
	SLL *next = NULL;

	while (current != NULL)
	{
		// Store the next SLL before changing the link
		next = current->next;
		// Reverse the 'next' pointer of the current SLL to point to the previous SLL
		current->next = prev;
		// Move the pointers one position forward
		prev = current;
		current = next;
	}
	// After the loop, 'prev' will be the new head of the reversed list
	*head = prev;
}

/**
 * @brief Prints the elements of the linked list.
 * @param SLL The head of the list to print.
 */
void printList(SLL *SLL)
{
	while (SLL != NULL)
	{
		printf("%d -> ", SLL->data);
		SLL = SLL->next;
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

	// Reverse the list
	reverseList(&head);

	printf("\nReversed list:\n");
	printList(head);

	return 0;
}