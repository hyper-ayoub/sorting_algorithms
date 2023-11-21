#include "sort.h"
#include <stdio.h>

/**
 * bubble_sort - Sorts an array of integers in ascending order
 *
 * @array: Array of integer
 * @size: Size of the array
 *
 * Return: void
 */
void bubble_sort(int *array, size_t size)
{
	size_t r;
	int _tmp, _sorted;

	if (!array || size == 0)
		return;

	do {
		_sorted = 1;
		for (r = 0; r < size - 1; r++)
		{
			if (array[r] > array[r + 1])
			{
				_sorted = 0;
				_tmp = array[r];
				array[r] = array[r + 1];
				array[r + 1] = _tmp;
				print_array(array, size);
			}
		}

	} while (_sorted == 0);
}
