#include "sort.h"
#include <stdlib.h>
#include <stdio.h>

/**
* merge - sorts and merges
* @start: starting index
* @md: end index
* @end: end index
* @desti: destination for data
* @source: source of data
*
* Return: void
*/
void merge(size_t start, size_t md, size_t end, int *desti, int *source)
{
	size_t i, j, k;

	printf("Merging...\n");
	printf("[left]: ");
	print_array(source + start, md - start);
	printf("[right]: ");
	print_array(source + md, end - md);
	i = start;
	j = md;
	for (k = start; k < end; k++)
	{
		if (i < md && (j >= end || source[i] <= source[j]))
		{
			desti[k] = source[i];
			i++;
		}
		else
		{
			desti[k] = source[j];
			j++;
		}
	}
	printf("[Done]: ");
	print_array(desti + start, end - start);
}

/**
* Split_The_Merge - recursively splits the array, merge and sort
* @start: starting the index
* @end: end index
* @array: the array to be sorted
* @clone: clone array
*/
void Split_The_Merge(size_t start, size_t end, int *array, int *clone)
{
	size_t md;

	if (end - start < 2)
		return;
	md = (start + end) / 2;
	Split_The_Merge(start, md, array, clone);
	Split_The_Merge(md, end, array, clone);
	merge(start, md, end, array, clone);
	for (md = start; md < end; md++)
		clone[md] = array[md];
}

/**
* merge_sort - sorts array of integers
* Merge sorting algorithm
* @array: array to be sorted
* @size: size of array
*
* Return: void
*/
void merge_sort(int *array, size_t size)
{
	size_t i;
	int *clone;

	if (array == NULL || size < 2)
		return;
	clone = malloc(sizeof(int) * size);
	if (clone == NULL)
		return;
	for (i = 0; i < size; i++)
		clone[i] = array[i];
	Split_The_Merge(0, size, array, clone);
	free(clone);
}
