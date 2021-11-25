#ifndef HEAP_SORT
#define HEAP_SORT

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void print_array(const int *array, size_t size);
void heap_sort(int *array, size_t size);
void siftDown(int *array, int n, int i, size_t size);
#endif
