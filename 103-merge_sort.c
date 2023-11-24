#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * copy_array - copies data from one buffer to another
 *
 * @source: source array
 * @destination: destination array
 * @size: size of arrays
 *
 * Return: No Return
 */
void copy_array(int *source, int *destination, int size)
{
	int i;

	for (i = 0; i < size; i++)
		destination[i] = source[i];
}

/**
 * merge_arrays - merges two sets of data in ascending order
 * assuming they are already sorted
 *
 * @main_array: main array to be merged
 * @buffer_array: buffer array to assist in merging
 * @min_left: lower range of the first set of data
 * @max_left: upper range of the first set of data
 * @min_right: lower range of the second set of data
 * @max_right: upper range of the second set of data
 *
 * Return: No Return
 */
void merge_arrays(int *main_array, int *buffer_array, int min_left, int max_left, int min_right, int max_right)
{
	int i = min_left, j = min_right, k = min_left;

	while (i <= max_left || j <= max_right)
	{
		if (i <= max_left && j <= max_right)
		{
			if (buffer_array[i] <= buffer_array[j])
				main_array[k] = buffer_array[i], k++, i++;
			else
				main_array[k] = buffer_array[j], k++, j++;
		}
		else if (i > max_left && j <= max_right)
		{
			main_array[k] = buffer_array[j], k++, j++;
		}
		else
		{
			main_array[k] = buffer_array[i], k++, i++;
		}
	}
}

/**
 * print_array_range - prints an array in a given range
 *
 * @array: array of data to be printed
 * @start: start of the range
 * @end: end of the range
 *
 * Return: No Return
 */
void print_array_range(int *array, int start, int end)
{
	int i;

	for (i = start; i <= end; i++)
	{
		if (i > start)
			printf(",");
		printf("%d", array[i]);
	}
	printf("\n");
}

/**
 * recursive_merge - recursive function to split data into a merge tree
 *
 * @main_array: main array of data to be split
 * @buffer_array: auxiliary array of data for merging
 * @min: min range of data in the array
 * @max: max range of data in the array
 * @size: size of the total data
 *
 * Return: No Return
 */
void recursive_merge(int *main_array, int *buffer_array, int min, int max, int size)
{
	int mid, temp_max, min_left, max_left, min_right, max_right;

	if ((max - min) <= 0)
		return;

	mid = (max + min + 1) / 2;
	temp_max = max;
	max = mid - 1;

	min_left = min;
	max_left = max;

	recursive_merge(main_array, buffer_array, min, max, size);

	min = mid;
	max = temp_max;

	min_right = min;
	max_right = max;

	recursive_merge(main_array, buffer_array, min, max, size);

	printf("Merging...\n");
	printf("[Left]:");
	print_array_range(main_array, min_left, max_left);

	printf("[Right]:");
	print_array_range(main_array, min_right, max_right);

	merge_arrays(main_array, buffer_array, min_left, max_left, min_right, max_right);
	copy_array(main_array, buffer_array, size);

	printf("[Done]:");
	print_array_range(main_array, min_left, max_right);
}

/**
 * merge_sort - sorts an array of integers in ascending order
 * using the Merge sort algorithm (recursive part)
 *
 * @array: array of data to be sorted
 * @size: size of data
 *
 * Return: No Return
 */
void merge_sort(int *array, size_t size)
{
	int *buffer_array;

	if (size < 2)
		return;

	buffer_array = malloc(sizeof(int) * size);
	if (buffer_array == NULL)
		return;

	copy_array(array, buffer_array, size);

	recursive_merge(array, buffer_array, 0, size - 1, size);

	free(buffer_array);
}

