#include <stdio.h>
#include <stdlib.h>

#define MAX 100

// Node structure for adjacency list
struct Node
{
	int vertex;
	struct Node *next;
};

// Graph structure
struct Graph
{
	int numVertices;
	struct Node **adjLists;
	int *visited;
};

// Queue for BFS
int queue[MAX], front = -1, rear = -1;

void enqueue(int value)
{
	if (rear == MAX - 1)
		return;
	if (front == -1)
		front = 0;
	queue[++rear] = value;
}

int dequeue()
{
	if (front == -1 || front > rear)
		return -1;
	return queue[front++];
}

int isEmpty()
{
	return front == -1 || front > rear;
}

// Create a node
struct Node *createNode(int v)
{
	struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
	newNode->vertex = v;
	newNode->next = NULL;
	return newNode;
}

// Create a graph
struct Graph *createGraph(int vertices)
{
	struct Graph *graph = malloc(sizeof(struct Graph));
	graph->numVertices = vertices;

	graph->adjLists = malloc(vertices * sizeof(struct Node *));
	graph->visited = malloc(vertices * sizeof(int));

	for (int i = 0; i < vertices; i++)
	{
		graph->adjLists[i] = NULL;
		graph->visited[i] = 0;
	}

	return graph;
}

// Add edge (undirected)
void addEdge(struct Graph *graph, int src, int dest)
{
	struct Node *newNode = createNode(dest);
	newNode->next = graph->adjLists[src];
	graph->adjLists[src] = newNode;

	newNode = createNode(src); // Add edge back (undirected)
	newNode->next = graph->adjLists[dest];
	graph->adjLists[dest] = newNode;
}

// BFS Function
void bfs(struct Graph *graph, int startVertex)
{
	enqueue(startVertex);
	graph->visited[startVertex] = 1;

	while (!isEmpty())
	{
		int currVertex = dequeue();
		printf("%d ", currVertex);

		struct Node *temp = graph->adjLists[currVertex];

		while (temp)
		{
			int adjVertex = temp->vertex;

			if (!graph->visited[adjVertex])
			{
				enqueue(adjVertex);
				graph->visited[adjVertex] = 1;
			}
			temp = temp->next;
		}
	}
}
// DFS Function
void dfs(struct Graph *graph, int vertex)
{
	graph->visited[vertex] = 1;
	printf("%d ", vertex);

	struct Node *temp = graph->adjLists[vertex];
	while (temp)
	{
		int adjVertex = temp->vertex;

		if (!graph->visited[adjVertex])
		{
			dfs(graph, adjVertex);
		}
		temp = temp->next;
	}
}
int main()
{
	int V = 6;
	struct Graph *graph = createGraph(V);

	addEdge(graph, 0, 1);
	addEdge(graph, 0, 2);
	addEdge(graph, 1, 3);
	addEdge(graph, 1, 4);
	addEdge(graph, 2, 5);

	printf("BFS Traversal: ");
	bfs(graph, 0);

	// Reset visited array for DFS
	for (int i = 0; i < V; i++)
		graph->visited[i] = 0;

	printf("\nDFS Traversal: ");
	dfs(graph, 0);

	return 0;
}
