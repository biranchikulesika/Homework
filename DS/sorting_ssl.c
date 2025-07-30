#include <stdio.h>
#include <stdlib.h>

// Structure for a node
typedef struct Node
{
	int data;
	struct Node *next;
} SLL;

// Function to create a new node
SLL *createNode(int data)
{
	SLL *newNode = (SLL *)malloc(sizeof(SLL));
	if (!newNode)
	{
		printf("Memory allocation failed\n");
		exit(EXIT_FAILURE);
	}
	newNode->data = data;
	newNode->next = NULL;
	return newNode;
}

// Insert at end
void insertEnd(SLL **head, int data)
{
	SLL *newNode = createNode(data);
	if (*head == NULL)
	{
		*head = newNode;
		return;
	}
	SLL *last = *head;
	while (last->next != NULL)
		last = last->next;
	last->next = newNode;
}

// Bubble sort the linked list
void sortLinkedList(SLL *head)
{
	if (head == NULL || head->next == NULL)
		return;

	int swapped;
	SLL *current;
	SLL *boundary = NULL;

	do
	{
		swapped = 0;
		current = head;

		while (current->next != boundary)
		{
			if (current->data > current->next->data)
			{
				// Swap data
				int temp_data = current->data;
				current->data = current->next->data;
				current->next->data = temp_data;
				swapped = 1;
			}
			current = current->next;
		}
		boundary = current;
	} while (swapped);
}

// Function to print the list
void printList(SLL *head)
{
	while (head != NULL)
	{
		printf("%d -> ", head->data);
		head = head->next;
	}
	printf("NULL\n");
}

// Function to free the list to prevent memory leaks
void freeList(SLL *head)
{
	SLL *node_to_free;
	while (head != NULL)
	{
		node_to_free = head;
		head = head->next;
		free(node_to_free);
	}
}

// Main function
int main()
{
	SLL *head = NULL;

	// Inserting unsorted values
	insertEnd(&head, 50);
	insertEnd(&head, 30);
	insertEnd(&head, 20);
	insertEnd(&head, 40);
	insertEnd(&head, 10);

	printf("Original list:\n");
	printList(head);

	sortLinkedList(head);

	printf("Sorted list:\n");
	printList(head);

	// Free the allocated memory for the list
	freeList(head);

	return 0;
}
