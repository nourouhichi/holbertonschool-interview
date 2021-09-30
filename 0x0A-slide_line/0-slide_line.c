#include "slide_line.h"
/**
 * slide_left - moves the line to the left
 * @line: array
 * @size: array size
 */
void slide_left(int *line, size_t size)
{
	size_t i, j, k;

	for (i = 0, j = 0; i < size; i++, j++)
	{
		if (line[i] == 0)
			while (line[i] == 0)
				i++;

		j = i + 1;

		if (line[j] == 0)
			while (line[j] == 0)
				j++;

		if (line[i] == line[j])
		{
			line[i] = line[i] * 2;
			line[j] = 0;
			i = j + 1;
		}
		else
			i++;

		j = 0;
	}

	for (i = 0, k = 0; i < size; i++)
		if (line[i] != 0)
			line[k++] = line[i];

	while (k < size)
		line[k++] = 0;
}


/**
 * slide_right - moves the line to left
 * @line: array
 * @size: size
 */
void slide_right(int *line, size_t size)
{
	size_t i, j;

	for (i = size; i > 0; i--)
	{
		for (j = i - 1; j > 0; j--)
		{
			if (line[i - 1] != 0)
			{
				if (line[i - 1] == line[j - 1])
				{
					line[i - 1] = line[i - 1] * 2;
					line[j - 1] = 0;
					break;
				}

				if (line[i - 1] != line[j - 1] &&
				    line[j - 1] != 0)
					break;
			}
			if (line[i - 1] == 0)
			{
				if (line[j - 1] != 0)
				{
					line[i - 1] = line[j - 1];
					line[j - 1] = 0;
					i++;
					break;
				}
			}
		}
	}
}

/**
 * slide_line - slides a line
 * @line: line
 * @size: size of the array.
 * @direction: direction to move
 * Return: 1 success 0 fail.
 */
int slide_line(int *line, size_t size, int direction)
{
	if (direction != SLIDE_LEFT && direction != SLIDE_RIGHT)
		return (0);
	if (direction == 0)
		slide_left(line, size);
	if (direction == 1)
		slide_right(line, size);
	return (1);
}
