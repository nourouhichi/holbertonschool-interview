#include "sort.h"
/**
 * current_digit_sort - sort by current digit
 * @array: array
 * @size: size of the array
 * @tmp: temporary array
 * @exp: expo
 * Return: sorted array
 */
int current_digit_sort(int *array, ssize_t size, int *tmp, long exp)
{
	ssize_t i;
	int aux[9] = {0};

	for (i = 0; i < size; i++)
		aux[(array[i] / exp) % 10]++, tmp[i] = 0;
	for (i = size - 1; i >= 0; i--)
		tmp[--aux[(array[i] / exp) % 10]] = array[i];
	for (i = 0; i < size; i++)
		array[i] = tmp[i];
	return (0);
}
/**
 * radix_sort - RADIX sort
 * @array: array
 * @size: size
 * Return: nothing
 */
void radix_sort(int *array, size_t size)
{
	size_t i;
	long exp = 1;
	int *tmp, max = INT_MIN;

	if (!array || size < 2)
		return;

	tmp = malloc(sizeof(long *) * size);
	if (!tmp)
		return;

	for (i = 0; i < size; i++)
		max = array[i] > max ? array[i] : max;
	free(tmp);
}
