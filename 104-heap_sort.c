#include "sort.h"

/**
 * adjust_heap - Adjusts the heap structure starting from a given root.
 * @array: The array representing the heap.
 * @root: The root index of the heap.
 * @end: The last index of the heap.
 * @size: The size of the array.
 */
void adjust_heap(int *array, size_t root, size_t end, size_t size)
{
	size_t left, right, swap;
	int temp;

	while ((left = (2 * root) + 1) <= end)
	{
		swap = root;
		right = left + 1;
		if (array[swap] < array[left])
			swap = left;
		if (right <= end && array[swap] < array[right])
			swap = right;
		if (swap == root)
			return;
		temp = array[root];
		array[root] = array[swap];
		array[swap] = temp;
		print_array(array, size);
		root = swap;
	}
}

/**
 * build_heap - Builds a heap from an unsorted array.
 * @array: The array to be turned into a heap.
 * @size: The size of the array.
 *
 * Return: void
 */
void build_heap(int *array, size_t size)
{
	size_t parent;

	for (parent = ((size - 1) - 1) / 2; 1; parent--)
	{
		adjust_heap(array, parent, size - 1, size);
		if (parent == 0)
			break;
	}
}

/**
 * heap_sort - Sorts an array of ints in ascending order using the Heap sort algorithm.
 * @array: The array to be sorted.
 * @size: The size of the array.
 *
 * Return: void
 */
void heap_sort(int *array, size_t size)
{
	size_t end;
	int temp;

	if (array == NULL || size < 2)
		return;
	build_heap(array, size);
	end = size - 1;
	while (end > 0)
	{
		temp = array[end];
		array[end] = array[0];
		array[0] = temp;
		print_array(array, size);
		end--;
		adjust_heap(array, 0, end, size);
	}
}

