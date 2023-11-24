#include "sort.h"
#include <stdio.h>
/**
 * swap - swap
 * @array: the array for swap
 * @i: the first index
 * @j: the second index
 * Return: No value
 */
void swap(int *array, int i, int j)
{
	int tmp;

	if (array[i] != array[j])
	{
		tmp = array[i];
		array[i] = array[j];
		array[j] = tmp;
	}
}

/**
 * shell_sort - sort the list
 * @array: array to sort.
 * @size: Size of array
 * Return: No value
 */
void shell_sort(int *array, size_t size)
{
	size_t h = 0,  i, j;

	if (size < 2)
		return;

	while (h <= size / 3)
		h = h * 3 + 1;

	while (h >= 1)
	{
		for (i = h; i < size; i++)
			for (j = i; j >= h && array[j] < array[j - h]; j -= h)
				swap(array, j, j - h);
		h /= 3;
		print_array(array, size);
	}
}
