// A question from Programming with ANSI C, sixth edition, page no. 147, question no. 5.3

/*
	ax1 + bx2 = m
	cx1 + dx2 = n
	x1 = md - bn/ad-cb
	x2 = na - mc/ad-cb
*/
#include <stdio.h>

int main()
{
	int x1, x2, a, b, c, d, m, n, den;

	printf("Enter the value of the constants:\n");
	printf("a = ");
	scanf("%d", &a);
	printf("b = ");
	scanf("%d", &b);
	printf("c = ");
	scanf("%d", &c);
	printf("d = ");
	scanf("%d", &d);
	printf("n = ");
	scanf("%d", &n);
	printf("m = ");
	scanf("%d", &m);

	den = a * d - b * c;

	if (den == 0)
	{
		printf("The value of ad-bc is 0, the equations have no unique solution.\n");
		return 1;
	}

	x1 = (m * d - b * n) / den;
	x2 = (n * a - m * c) / den;

	printf("X1 = %d\nX2 = %d\n\n", x1, x2);
	return 0;
}
