#ifndef _SORTH_
#define _SORTH_

#include <stdio.h>
#include<stdlib.h>
void print_array(const int *array, size_t size);
void merge_sort(int *array, size_t size);
void split(int *tmp, int *array, int start, int end);
void merge(int *array, int *tmp, int s, int m, int e);
#endif
