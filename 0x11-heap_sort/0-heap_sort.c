#include "sort.h"
/**
 *siftDown - sift_down heap sort algorithm
*@array: array to sort
*@n: int
*@i: int
*@size: size
*/

void siftDown(int *array, int n, int i, size_t size)
{

int max = i, tmp;
int l = 2 * i + 1;
int r = 2 * i + 2;

if (l <= n && (r > n || array[l] > array[r]) && array[l] > array[max])
max = l;
if (r <= n && array[r] > array[max] && array[r] >= array[l])
max = r;
if (max != i)
{
tmp = array[i];
array[i] = array[max];
array[max] = tmp;
print_array(array, size);
siftDown(array, n, max, size);
}
}

/**
 * heap_sort- sort an array with heap sort
 * @array: array to sort
 * @size: size
 */
void heap_sort(int *array, size_t size)
{
int i, j;
int tmp;

if (!array || size <= 1)
return;
for (i = (int)size - 1; i > 0; i--)
{
for (j = i; j >= 0; j--)
{
siftDown(array, i, j, size);
}
tmp = array[0];
array[0] = array[i];
array[i] = tmp;
print_array(array, size);
}
}
