#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX 100

char stack[MAX];
int top = -1;

int precedence(char op)
{
	if (op == '^')
		return 3;
	if (op == '*' || op == '/' || op == '%')
		return 2;
	if (op == '+' || op == '-')
		return 1;
	return 0;
}

void push(char ch)
{
	stack[++top] = ch;
}

char pop()
{
	if (top == -1)
		return -1;
	return stack[top--];
}

char peek()
{
	return (top == -1) ? -1 : stack[top];
}

void infixToPostfix(char *infix)
{
	top = -1; // Reset stack for each conversion
	char postfix[MAX] = {0};
	int j = 0;

	for (int i = 0; infix[i]; i++)
	{
		char ch = infix[i];

		if (isalnum(ch))
		{
			postfix[j++] = ch;
		}
		else if (ch == '(')
		{
			push(ch);
		}
		else if (ch == ')')
		{
			while (peek() != '(')
				postfix[j++] = pop();
			pop(); // Remove '('
		}
		else
		{ // operator
			while (precedence(ch) <= precedence(peek()))
				postfix[j++] = pop();
			push(ch);
		}
	}

	while (top != -1)
		postfix[j++] = pop();

	postfix[j] = '\0';
	strcpy(infix, postfix); // Copy the result back to the input string
}

void reverse(char *str)
{
	int len = strlen(str);
	for (int i = 0; i < len / 2; i++)
	{
		char tmp = str[i];
		str[i] = str[len - i - 1];
		str[len - i - 1] = tmp;
	}
}

void swapParens(char *str)
{
	for (int i = 0; str[i]; i++)
	{
		if (str[i] == '(')
			str[i] = ')';
		else if (str[i] == ')')
			str[i] = '(';
	}
}

void infixToPrefix(char *infix)
{
	reverse(infix);
	swapParens(infix);
	infixToPostfix(infix);
	reverse(infix);
}

int main()
{
	char infix_exp[MAX];
	char prefix_exp[MAX];

	printf("Enter Infix Expression: ");
	scanf("%s", infix_exp);

	// Make a copy for the prefix conversion since the functions modify the string
	strcpy(prefix_exp, infix_exp);

	infixToPostfix(infix_exp);
	printf("Postfix Expression: %s\n", infix_exp);

	infixToPrefix(prefix_exp);
	printf("Prefix Expression: %s\n", prefix_exp);
	return 0;
}
