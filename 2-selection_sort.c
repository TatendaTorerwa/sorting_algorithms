#include "sort.h"


/**
 * selection_sort - Sorts an array of integers using selection sort.
 *
 * @array: Array to be sorted.
 *
 * @size: Number of integers in the array.
 *
 * Description: Prints the array after each swap.
 */

void selection_sort(int *array, size_t size)
{
	int temp;
	size_t p, j;

	if (array == NULL || size < 2)
	{
		return;
	}

	for (p = 0; p < size - 1; p++)
	{
		size_t min = p;

		for (j = p + 1; j < size; j++)
		{
			if (array[j] < array[min])
			{
				min = j;
			}
		}
		if (min != p)
		{
			temp = array[p];
			array[p] = array[min];
			array[min] = temp;

			print_array(array, size);
		}
	}
}
