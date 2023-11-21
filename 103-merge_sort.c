#include "sort.h"


void merge(int *subarray, size_t lower_bound, size_t mid,
                size_t upper_bound);
void merge_sort_recursive(int *subarray, size_t lower_bound, size_t upper_bound);
void merge_sort(int *array, size_t size);

/**
 * merge - Merge two sub-arrays into a sorted array.
 *
 * @subarray: Pointer to the array.
 *
 * @lower_bound: Size of the left sub-array.
 *
 * @upper_bound: Size of the right sub-array.
 *
 * @mid: The middle index of the array.
 */

void merge(int *subarray, size_t lower_bound, size_t mid, size_t upper_bound)
{
	size_t i = lower_bound;
	size_t j = mid + 1;
	size_t k = lower_bound;
	int *array_b;

	array_b = (int *)malloc((upper_bound + 1) * sizeof(int));
	if (array_b == NULL)
		return;

	print_array(subarray + lower_bound, mid - lower_bound + 1);
	print_array(subarray + mid + 1, upper_bound - mid);

	while (i <= mid && j <= upper_bound)
	{
		if (subarray[i] <= subarray[j])
		{
			array_b[k] = subarray[i];
			i++;
			k++;
		}
		else
		{
			array_b[k] = subarray[j];
			j++;
			k++;
		}
	}
	if (i > mid)
	{
		while (j <= upper_bound)
		{
			array_b[k] = subarray[j];
			j++;
			k++;
		}
	}
	else
	{
		while (i <= mid)
		{
			array_b[k] = subarray[i];
			i++;
			k++;
		}
	}
	for (k = lower_bound; k <= upper_bound; k++)
	{
		subarray[k] = array_b[k];
	}
    printf("Merging...\n[left]: ");
    print_array(subarray + lower_bound, upper_bound - lower_bound + 1);
    printf("[right]: ");
    print_array(subarray + mid + 1, upper_bound - mid);
    printf("[Done]: ");
    print_array(subarray + lower_bound, upper_bound - lower_bound + 1);


	free(array_b);
}

/**
 * merge_sort_recursive - Implement the merge sort algorithm through recursion.
 *
 * @subarray: A subarray of an array of integers to sort.
 *
 * @upper_bound: The front index of the subarray.
 *
 * @lower_bound: The back index of the subarray.
 */

void merge_sort_recursive(int *subarray, size_t lower_bound, size_t upper_bound)
{
	if (lower_bound < upper_bound)
	{
		size_t mid = (lower_bound + upper_bound) / 2;

		merge_sort_recursive(subarray, lower_bound, mid);
		merge_sort_recursive(subarray, mid + 1, upper_bound);
		merge(subarray, lower_bound, mid, upper_bound);
	}
}

/**
 * merge_sort - Sort an array of integers in ascending
 *              order using the merge sort algorithm.
 *
 * @array: An array of integers.
 *
 * @size: The size of the array.
 *
 * Description: Implements the top-down merge sort algorithm.
 */

void merge_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	merge_sort_recursive(array, 0, size - 1);
}
