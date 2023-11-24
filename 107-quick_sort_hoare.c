#include "sort.h"
/**
* hoare_partition - Implements the Hoare partition scheme for quicksort
* @arr: Array to sort
* @low: Lowest index
* @high: Highest index
* @size: Size of the array
*
* Return: Partition index
*/
size_t hoare_partition(int *arr, ssize_t low, ssize_t high, size_t size)
{
	int swap, pivot;

	pivot = arr[high];
	while (low <= high)
	{
		while (arr[low] < pivot)
			low++;
		while (arr[high] > pivot)
			high--;
		if (low <= high)
		{
			if (low != high)
			{
				swap = arr[low];
				arr[low] = arr[high];
				arr[high] = swap;
				print_array(arr, size);
			}
			low++;
			high--;
		}
	}
	return (high);
}

/**
* hoare_quicksort - Recursively sorts a partition of an array using the
*                   Hoare partition scheme for quicksort
* @arr: Array to sort
* @low: Lowest index of the partition to sort
* @high: Highest index of the partition to sort
* @size: Size of the array
*
* Return: void
*/
void hoare_quicksort(int *arr, ssize_t low, ssize_t high, size_t size)
{
	ssize_t pivot;

	if (low < high)
	{
		pivot = hoare_partition(arr, low, high, size);
		hoare_quicksort(arr, low, pivot, size);
		hoare_quicksort(arr, pivot + 1, high, size);
	}
}

/**
* quick_sort_hoare - Sorts an array of integers using the quicksort algorithm
*                    with the Hoare partition scheme
* @arr: The array to sort
* @size: The size of the array
*/
void quick_sort_hoare(int *arr, size_t size)
{
	if (arr == NULL || size < 2)
		return;
	hoare_quicksort(arr, 0, size - 1, size);
}

