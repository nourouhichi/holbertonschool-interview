#include "sort.h"
/**
 * merge - sorts by merging
 *
 * @tmp: temporrary holder
 * @array: array to be sorted
 * @s: index of beg
 * @m: the index of the middle
 * @e: index of end
 */
void merge(int *array, int *tmp, int s, int m, int e)
{
int i = s, j = m, k = s;
printf("Merging...\n[left]: ");
print_array((const int *)&tmp[s], m - s);
printf("[right]: ");
print_array((const int *)&tmp[m], e - m + 1);
while (i < m && j <= e)
{
if (tmp[i] < tmp[j])
{
array[k] = tmp[i];
i++;
k++;
}
else
{
array[k] = tmp[j];
j++;
k++;
}
}
while (i < m)
{
array[k] = tmp[i];
i++;
k++;
}
while (j <= e)
{
array[k] = tmp[j];
j++;
k++;
}
printf("[Done]: ");
for (i = s; i <= e; i++)
tmp[i] = array[i];
print_array((const int *)&array[s], e - s + 1);
}
/**
 * split - splits until size 3 or 4
 *
 * @tmp: temporrary holder
 * @array: array to be sorted
 * @start: index of beg
 * @end: index of end
 */
void split(int *tmp, int *array, int start, int end)
{
if ((end - start + 1) < 2)
return;
split(tmp, array, start, ((end - start + 1) / 2) + start - 1);
split(tmp, array, ((end - start + 1) / 2) + start, end);
merge(array, tmp, start, ((end - start + 1) / 2) + start, end);
return;
}

/**
 * merge_sort - merging sort op
 *
 * @array: The array to be printed
 * @size: Number of elements in @array
 */
void merge_sort(int *array, size_t size)
{
int *tmp = malloc(sizeof(int) * size), i, n;

if (!tmp || !array)
return;
n = (int)size;
for (i = 0; i != n; i++)
tmp[i] = array[i];
split(tmp, array, 0, n - 1);
free(tmp);
return;
}
