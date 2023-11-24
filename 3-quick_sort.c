#include "sort.h"

/**
 * tac_the_items - swaps items
 * @array: array to modify.
 * @l: index of left item.
 * @r: index of right item.
 */
void tac_the_items(int *array, size_t l, size_t r)
{
	int tmp;

	if (array != NULL)
	{
		tmp = array[l];
		array[l] = array[r];
		array[r] = tmp;
	}
}

/**
 * quick_lomuto - sort the sub array 
 * @array: The array of the sub_array.
 * @low: start position of the sub_array.
 * @high: end position of the sub_array.
 * @size: length of array.
 */
void quick_lomuto(int *array, size_t low, size_t high, size_t size)
{
	size_t k, i;
	int pivot;

	if ((low >= high) || (array == NULL))
		return;
	pivot = array[high];
	k = low;
	for (i = low; i < high; i++)
	{
		if (array[i] <= pivot)
		{
			if (k != i)
			{
				tac_the_items(array, k, i);
				print_array(array, size);
			}
			k++;
		}
	}
	if (k != high)
	{
		tac_the_items(array, k, high);
		print_array(array, size);
	}
	if (k - low > 1)
		quick_lomuto(array, low, k - 1, size);
	if (high - k > 1)
		quick_lomuto(array, k + 1, high, size);
}

/**
 * quick_sort - sorts the  array
 * @array: array to sort.
 * @size: length of the array.
 */
void quick_sort(int *array, size_t size)
{
	if (array != NULL)
	{
		quick_lomuto(array, 0, size - 1, size);
	}
}
