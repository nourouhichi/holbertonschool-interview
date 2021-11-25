#ifndef HEAP_SORT
#define HEAP_SORT

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void print_array(const int *array, size_t size);
void heap_sort(int *array, size_t size);
void max_heap(int *array, size_t n);
void heapify(int *array, int compteur, size_t n);

#endif
