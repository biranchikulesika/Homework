#include <stdio.h>
#include <stdlib.h>
#include <string.h> // Added missing header for strlen and strncpy

int gcd(int a, int b)
{
	while (b != 0)
	{
		int temp = b;
		b = a % b;
		a = temp;
	}
	return a;
}

int isDivisible(char *str, char *pattern)
{
	int len1 = strlen(str), len2 = strlen(pattern);

	if (len1 == 0 || len2 == 0 || (len1 % len2 != 0))
	{
		return 0;
	}

	for (int i = 0; i < len1; i++)
	{
		if (str[i] != pattern[i % len2])
		{
			return 0;
		}
	}
	return 1;
}

char *gcdOfStrings(char *str1, char *str2)
{
	int len1 = strlen(str1), len2 = strlen(str2);

	int gcdLen = gcd(len1, len2);

	char *pattern = (char *)malloc((gcdLen + 1) * sizeof(char));

	if (pattern == NULL)
	{
		return "";
	}

	strncpy(pattern, str1, gcdLen);
	pattern[gcdLen] = '\0';

	if (isDivisible(str1, pattern) && isDivisible(str2, pattern))
	{
		return pattern;
	}
	return "";
}

int main()
{
	char *str1 = (char *)malloc(100 * sizeof(char));
	char *str2 = (char *)malloc(100 * sizeof(char));

	if (str1 == NULL || str2 == NULL)
	{
		printf("Memory allocation failed.\n");
		return 1;
	}

	printf("\nWelcome to GCD of Strings.\n\n");

	printf("Enter the string 1: ");
	scanf("%99[^\n]", str1);
	getchar();

	printf("Enter the string 2: ");
	scanf("%99[^\n]", str2);

	char *result = gcdOfStrings(str1, str2);
	printf("str1: %s\nstr2: %s\ngcd of strings: %s\n", str1, str2, result);

	free(str1);
	free(str2);
	free(result);

	return 0;
}