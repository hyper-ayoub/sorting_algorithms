#include "sort.h"

/**
 * calculate_power_of_10 - Calculates a positive power of 10.
 * @power: Power of 10 to calculate.
 * Return: Final result.
 */
unsigned int calculate_power_of_10(unsigned int power)
{
	unsigned int i, result;

	result = 1;
	for (i = 0; i < power; i++)
		result *= 10;
	return (result);
}

/**
 * custom_count_sort - Performs counting sort on an array of integers.
 * @array: Array to be sorted.
 * @size: Size of the array to be sorted.
 * @digit: Digit to sort.
 *
 * Return: 1 if further sorting is needed, otherwise 0.
 */
unsigned int custom_count_sort(int *array, size_t size, unsigned int digit)
{
	int i, count[10] = {0};
	int *cpy = NULL;
	size_t j, temp, total = 0;
	unsigned int divisor1, divisor2, sort = 0;

	divisor2 = calculate_power_of_10(digit - 1);
	divisor1 = divisor2 * 10;
	cpy = malloc(sizeof(int) * size);
	if (cpy == NULL)
		exit(1);

	for (j = 0; j < size; j++)
	{
		cpy[j] = array[j];
		if (array[j] / divisor1 != 0)
			sort = 1;
	}

	for (i = 0; i < 10; i++)
		count[i] = 0;

	for (j = 0; j < size; j++)
		count[(array[j] % divisor1) / divisor2] += 1;

	for (i = 0; i < 10; i++)
	{
		temp = count[i];
		count[i] = total;
		total += temp;
	}

	for (j = 0; j < size; j++)
	{
		array[count[(cpy[j] % divisor1) / divisor2]] = cpy[j];
		count[(cpy[j] % divisor1) / divisor2] += 1;
	}

	free(cpy);
	return (sort);
}

/**
 * radix_sort - Implements a custom Radix sort algorithm.
 * @array: Array to sort.
 * @size: Size of the array.
 */
void radix_sort(int *array, size_t size)
{
	unsigned int i, sort = 1;

	if (array == NULL || size < 2)
		return;

	for (i = 1; sort == 1; i++)
	{
		sort = custom_count_sort(array, size, i);
		print_array(array, size);
	}
}

