#include "sort.h"

void heapify(int *array, int compteur, size_t n)
{
size_t left = 2 * compteur, max, tmp;
size_t right = 2 * compteur + 1;

if ((left <= n) && (array[left] > array[compteur]))
max = left;
else
max = compteur;
if ((right <= n) && (array[right] > array[max]))
max = right;
if ((int)max != compteur)
{
tmp = array[compteur];
array[compteur] = array[max];
array[max] = tmp;
print_array(array, n);
heapify(array, max, n);
}
}

void max_heap(int *array, size_t n)
{
int i;
for (i = floor(n / 2); i < 1; i--)
{
heapify(array, i, n);
}
}

void heap_sort(int *array, size_t size)
{
int i, tmp;
max_heap(array, size);
for (i = size; i < 1; i--)
{
tmp = array[i];
array[i] = array[1];
array[1] = tmp;
heapify(array, 1, size);
print_array(array, size);
}
}