#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
	int data;
	struct Node *left;
	struct Node *right;
} TREE;

// Function to create a new node
TREE *createNode(int value)
{
	TREE *newNode = (TREE *)malloc(sizeof(TREE));
	if (newNode == NULL)
	{
		// It's good practice to handle allocation failure.
		perror("Failed to allocate memory for new node");
		exit(EXIT_FAILURE);
	}
	newNode->data = value;
	newNode->left = newNode->right = NULL;
	return newNode;
}
void inorder(TREE *root)
{
	if (root != NULL)
	{
		inorder(root->left);
		printf("%d ", root->data);
		inorder(root->right);
	}
}
void preorder(TREE *root)
{
	if (root != NULL)
	{
		printf("%d ", root->data);
		preorder(root->left);
		preorder(root->right);
	}
}
void postorder(TREE *root)
{
	if (root != NULL)
	{
		postorder(root->left);
		postorder(root->right);
		printf("%d ", root->data);
	}
}

// Function to insert a new node. It uses a double pointer to modify the root.
void insert(TREE **root, int value)
{
	if (*root == NULL)
	{
		*root = createNode(value);
		return;
	}

	if (value < (*root)->data)
		insert(&((*root)->left), value);
	else if (value > (*root)->data)
		insert(&((*root)->right), value);
	// Note: Duplicate values are ignored.
}
TREE *search(TREE *root, int key)
{
	if (root == NULL || root->data == key)
		return root;

	if (key < root->data)
		return search(root->left, key);
	else
		return search(root->right, key);
}
TREE *findMin(TREE *root)
{
	while (root && root->left != NULL)
		root = root->left;
	return root;
}

TREE *findMax(TREE *root)
{
	while (root && root->right != NULL)
		root = root->right;
	return root;
}

// Function to delete a node. It uses a double pointer to modify the tree structure.
void delete(TREE **root, int key)
{
	if (*root == NULL)
	{
		// Key not found, or tree is empty.
		return;
	}

	// Find the node to be deleted
	if (key < (*root)->data)
		delete(&((*root)->left), key);
	else if (key > (*root)->data)
		delete(&((*root)->right), key);
	else
	{
		// Node with the key has been found
		TREE *nodeToDelete = *root;

		if ((*root)->left == NULL)
		{ // Case 1 & 2: Node has no left child (covers no child and right child only)
			*root = (*root)->right;
			free(nodeToDelete);
		}
		else if ((*root)->right == NULL)
		{ // Case 2: Node has only a left child
			*root = (*root)->left;
			free(nodeToDelete);
		}
		else
		{ // Case 3: Node has two children
			TREE *inorderSuccessor = findMin((*root)->right);
			(*root)->data = inorderSuccessor->data;
			delete(&((*root)->right), inorderSuccessor->data);
		}
	}
}
int main()
{
	TREE *root = NULL;

	insert(&root, 50);
	insert(&root, 30);
	insert(&root, 20);
	insert(&root, 40);
	insert(&root, 70);
	insert(&root, 60);

	inorder(root);
	printf("\n");
	preorder(root);
	printf("\n");
	postorder(root);

	int key = 80;

	if (search(root, key))
		printf("\n%d Found!", key);
	else
		printf("\n%d Not Found!", key);

	printf("\nThe smallest element: %d", (findMin(root))->data);
	printf("\nThe largest element: %d", (findMax(root))->data);
	return 0;
}
