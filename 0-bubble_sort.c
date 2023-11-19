#include "sort.h"


/**
 * swap - Swap two integers in an array.
 * @a: The first integer to swap.
 * @b: The second integer to swap.
 */

void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

/**
 * bubble_sort - Sort an array of integers using bubble sort.
 *
 * @array: The array of integers.
 *
 * @size: The number of integers in the array.
 *
 * Description: Prints the array after each swap.
 */

void bubble_sort(int *array, size_t size)
{
	size_t p, j;
	int flag;

	if (array == NULL || size < 2)
		return;

	for (p = 0; p < size - 1; p++)
	{
		flag = 0;

		for (j = 0; j < size - 1 - p; j++)
		{
			if (array[j] > array[j + 1])
			{
				swap(&array[j], &array[j + 1]);
				print_array(array, size);
				flag = 1;
			}
		}
		if (flag == 0)
		{
			break;
		}
	}
}
