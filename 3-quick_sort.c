#include "sort.h"

/**
 * swap - Swaps two integers in an array.
 *
 * @a: The first integer.
 *
 * @b: The second integer.
 */

void swap(int *a, int *b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 * lomuto_partition - Divides an array into two parts during the sort.
 *
 * @array: The array to be divided.
 *
 * @start: The starting index of the subset to order.
 *
 * @end: The ending index of the subset to order.
 *
 * @size: The size of the array.
 *
 * Return: The fnal partition index.
 */

int lomuto_partition(int *array, size_t size,  int start, int end)
{
	int pivot = array[end];
	int p = start - 1;
	int j;

	for (j = start; j < end; j++)
	{
		if (array[j] <= pivot)
		{
			p++;
			swap(&array[p], &array[j]);
			print_array(array, size);
		}
	}
	swap(&array[p + 1], &array[end]);
	print_array(array, size);

	return (p + 1);
}

/**
 * quick_sorting - QuickSort algorithm to sort an array of integers.
 *
 * @array: The array to be sorted.
 *
 * @lower_bound: The lower index of the current subarray or partition.
 *
 * @upper_bound: The higher index of the current subarray or partition.
 *
 * Description: Use the lomuto partition scheme.
 */

void quick_sorting(int *array, size_t size, int lower_bound, int upper_bound)
{
	if (lower_bound < upper_bound)
	{
		int loc = lomuto_partition(array, size, lower_bound, upper_bound);
		quick_sorting(array, size, lower_bound, loc - 1);
		quick_sorting(array, size, loc + 1, upper_bound);
	}
}

/**
 * quick_sort - Sort an array of integers using quick sort.
 *
 * @array: An array to be sorted.
 *
 * @size: The size of the array.
 *
 * Description: Prints the array after each swap.
 */

void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	quick_sorting(array, size, 0, size - 1);
}
