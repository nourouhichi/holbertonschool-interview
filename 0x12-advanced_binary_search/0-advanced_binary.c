
#include "search_algos.h"

/**
* print_array - Print an array of integers
* @array: The array to be printed
* @size: Number of elements
* @i: position to print from
*/
void print_array(int *array, size_t i, size_t size)
{
if (i > size)
return;
printf("%d", array[i]);
if (i < size)
printf(", ");
print_array(array, i + 1, size);
}

/**
* advanced_binary - search for a value in a sorted array of integers
* @array: pointer to the first element of the array to search in
* @size: array size
* @value: the value to search for
* Return: return the index where value is located
*/

int advanced_binary(int *array, size_t size, int value)
{
size_t low = 0;
size_t high = size - 1;
size_t m;

if (!array)
return (-1);
while (low <= high)
{
printf("Searching in array: ");
print_array(array, low, high);
printf("\n");

m = (low + high) / 2;
if (array[m] == value && array[m - 1] != value)
return (m);
else if (array[m] < value)
low = m + 1;
else
high = m;
}
return (-1);
}