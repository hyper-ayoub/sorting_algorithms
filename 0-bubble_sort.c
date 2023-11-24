#include "sort.h"
#include <stdio.h>

/**
 * bubble_sort - sorts an array of integers using bubble
 *
 * @array: array of the integer
 * @size: size of array
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
