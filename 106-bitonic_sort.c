#include "sort.h"
#include <stdio.h>

/**
 * cmp_bitonic - Compare and swap elements in a bitonic sequence.
 * @up: Direction of sorting.
 * @array: Sub-array to sort.
 * @size: Size of the sub-array.
 */
void cmp_bitonic(char up, int *array, size_t size)
{
	size_t i, hsz;
	int swap;

	hsz = size / 2;
	for (i = 0; i < hsz; i++)
	{
		if ((array[i] > array[i + hsz]) == up)
		{
			swap = array[i];
			array[i] = array[i + hsz];
			array[i + hsz] = swap;
		}
	}
}

/**
 * merge_bitonic - Recursively merge sub-arrays in a bitonic sequence.
 * @up: Direction of sorting.
 * @array: Sub-array to sort.
 * @size: Size of the sub-array.
 */
void merge_bitonic(char up, int *array, size_t size)
{
	if (size < 2)
		return;

	cmp_bitonic(up, array, size);
	merge_bitonic(up, array, size / 2);
	merge_bitonic(up, array + (size / 2), size / 2);
}

/**
 * rec_bitonic_sort - Recursively apply the bitonic sort algorithm.
 * @up: Direction of sorting.
 * @array: Sub-array to sort.
 * @size: Size of the sub-array.
 * @ts: Total size of the original array.
 */
void rec_bitonic(char up, int *array, size_t size, size_t ts)
{
	if (size < 2)
		return;

	printf("Merging [%lu/%lu] (%s):\n", size, ts, (up == 1) ? "UP" : "DOWN");
	print_array(array, size);

	rec_bitonic(1, array, size / 2, ts);
	rec_bitonic(0, array + (size / 2), size / 2, ts);

	merge_bitonic(up, array, size);

	printf("Result [%lu/%lu] (%s):\n", size, ts, (up == 1) ? "UP" : "DOWN");
	print_array(array, size);
}

/**
 * bitonic_sort - Sort an array.
 * @array: Array sort.
 * @size: Size of array.
 */
void bitonic_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	rec_bitonic(1, array, size, size);
}

