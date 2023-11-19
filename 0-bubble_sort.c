#include "sort.h"

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
	size_t p, j, k;
	int temp;

	for (p = 0; p < size - 1; p++)
	{
		for (j = 0; j < size - 1 - p; j++)
		{
			if (array[j] > array[j + 1])
			{
				temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;

				for (k = 0; k < size; k++)
				{
					printf("%d ", array[k]);
				}
				printf("\n");
			}
		}
	}
}
