#include "sort.h"
#include <stdio.h>

/**
 * compare_bitonic - Compare and swap elements in a bitonic sequence.
 * @up: Direction of sorting.
 * @array: Sub-array to sort.
 * @size: Size of the sub-array.
 */
void compare_bitonic(char up, int *array, size_t size)
{
	size_t i, half_size;
	int swap;

	half_size = size / 2;
	for (i = 0; i < half_size; i++)
	{
		if ((array[i] > array[i + half_size]) == up)
		{
			swap = array[i];
			array[i] = array[i + half_size];
			array[i + half_size] = swap;
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

	compare_bitonic(up, array, size);
	merge_bitonic(up, array, size / 2);
	merge_bitonic(up, array + (size / 2), size / 2);
}

/**
 * recursive_bitonic_sort - Recursively apply the bitonic sort algorithm.
 * @up: Direction of sorting.
 * @array: Sub-array to sort.
 * @size: Size of the sub-array.
 * @total_size: Total size of the original array.
 */
void recursive_bitonic_sort(char up, int *array, size_t size, size_t total_size)
{
	if (size < 2)
		return;

	printf("Merging [%lu/%lu] (%s):\n", size, total_size, (up == 1) ? "UP" : "DOWN");
	print_array(array, size);

	recursive_bitonic_sort(1, array, size / 2, total_size);
	recursive_bitonic_sort(0, array + (size / 2), size / 2, total_size);

	merge_bitonic(up, array, size);

	printf("Result [%lu/%lu] (%s):\n", size, total_size, (up == 1) ? "UP" : "DOWN");
	print_array(array, size);
}

/**
 * bitonic_sort - Sort an array in ascending order using the bitonic sort algorithm.
 * @array: Array to sort.
 * @size: Size of the array.
 */
void bitonic_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	recursive_bitonic_sort(1, array, size, size);
}

