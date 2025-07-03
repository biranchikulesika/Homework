#include <stdio.h>

void pm(int start, int end)
{
	printf("%d -> %d\n", start, end);
}

void hanoi(int n, int start, int end)
{
	int other;

	if (n == 1)
	{
		pm(start, end);
	}
	else
	{
		other = 6 - (start + end);
		hanoi(n - 1, start, other);
		pm(start, end);
		hanoi(n - 1, other, end);
	}
}

int main()
{
	int n, start = 1, end = 3;
	printf("The Peg Hanoi\nEnter number of disks: ");
	scanf("%d", &n);

	hanoi(n, start, end);

	return 0;
}