#include <stdio.h>

#define MAX 30

typedef struct instack {
	int top;
	int arr[MAX];
} Stack;
typedef Stack* StackPtr;

void initStack(StackPtr s) {
	s->top = -1;
}
void push(StackPtr s, int value) {
	if (s->top == MAX - 1) { 
		printf("Stack overflow\n");
		return;
	}
	s->arr[++(s->top)] = value;
}
int pop(StackPtr s) {
	if (s->top == -1) {
		printf("Stack underflow\n");
		return -1;
	}
	return s->arr[(s->top)--];
}
int peek(StackPtr s) {
	if (s->top == -1) {
		printf("Stack is empty\n");
		return -1;
	}
	return s->arr[s->top];
}
int isEmpty(StackPtr s) {
	return s->top == -1;
}
int isFull(StackPtr s) {
	return s->top == MAX - 1;
}
void display(StackPtr s) {
	if (isEmpty(s)) {
		printf("Stack is empty\n");
		return;
	}
	printf("Stack elements: ");
	for (int i = 0; i <= s->top; i++) {
		printf("%d ", s->arr[i]);
	}
	printf("\n");
}
int main() {
	Stack s;
	initStack(&s);

	push(&s, 10);
	push(&s, 20);
	push(&s, 30);
	display(&s);

	printf("Popped element: %d\n", pop(&s));
	display(&s);

	printf("Top element: %d\n", peek(&s));

	return 0;
}
// This code implements a stack data structure using an array in C.
// It includes functions to initialize the stack, push and pop elements,
// check if the stack is empty or full, and display the elements in the stack.
// The main function demonstrates the usage of these functions.
// The stack is implemented using a structure that contains an array and a top index.
// The stack has a maximum size defined by the constant MAX.
// The stack operations are performed using functions that take a pointer to the stack structure.
// The stack is initialized with a top index of -1, indicating that it is empty.
// The push function adds an element to the top of the stack, while the pop function removes
// the top element and returns it. The peek function returns the top element without removing it.
// The isEmpty and isFull functions check the status of the stack.
// The display function prints the elements in the stack.
// The main function demonstrates the usage of these functions by pushing and popping elements
// and displaying the stack contents. The program returns 0 to indicate successful
// completion.
// The stack is implemented using an array, which has a fixed size defined by the constant MAX.