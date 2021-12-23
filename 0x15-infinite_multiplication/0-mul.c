#include "holberton.h"
#include <stdlib.h>


/**
 * _strlen - length of a string
 *
 * @s: Pointer to string
 * Return: length
 */

int _strlen(char *s)
{
	int i;

	i = 0;
	while (*s != '\0')
	{
	s++;
	i++;
	}
	return (i);
}

/**
 * error - stderr print
 * Return: exit
 */
void error(void)
{
	int i;
	char erro[] = "Error\n";

	for (i = 0; i <= 5; i++)
		_putchar(erro[i]);
	exit(98);
}

/**
 * results - results
 * @z1: 0
 * @z2: 0
 * @len: lenght of answer
 * @ans: pointer to answer
 *
 * Return: longitud of string
 */

void results(int z1, int z2, int len, int *ans)
{
	int i;

	if (z1 == 0 || z2 == 0)
		_putchar('0');
	else
	{
		for (i = len - 1; i >= 0; i--)
			if (i != len - 1 || ans[i] != 0)
				_putchar(ans[i] + '0');
	}
	_putchar('\n');
}

/**
 * main - check the code for Holberton School students.
 *@argc: Counts arguments in argv
 *@argv: args
 * Return: 0
 */
int main(int argc, char *argv[])
{
	int i, j, tmp, l1, l2, len, *a, *b, *ans, z1 = 0, z2 = 0;

	if (argc != 3 || argv[1] == NULL || argv[2] == NULL)
		error();
	l1 = strlen_(argv[1]);
	l2 = strlen_(argv[2]);
	len = l1 + l2;
	ans = malloc(len * sizeof(int));
	a = malloc(l1 * sizeof(int));
	b = malloc(l2 * sizeof(int));

	for (i = l1 - 1, j = 0; i >= 0; i--, j++)
		{
		a[j] = argv[1][i] - '0';
		if (a[j] < 0 || a[j] > 9)
			error();
		z1 += a[j];
		}
	for (i = l2 - 1, j = 0; i >= 0; i--, j++)
		{
		b[j] = argv[2][i] - '0';
		if (b[j] < 0 || b[j] > 9)
			error();
		z2 += b[j];
		}
	for (i = 0; i < l2; i++)
		for (j = 0; j < l1; j++)
			ans[i + j] = ans[i + j] + b[i] * a[j];
	for (i = 0; i < len; i++)
		{
		tmp = ans[i] / 10;
		ans[i] = ans[i] % 10;
		ans[i + 1] = ans[i + 1] + tmp;
		}
	results(z1, z2, len, ans);
	free(a);
	free(b);
	free(ans);
	return (0);
}
