#include "sort.h"

/**
 *  counting_sort - Sorts an array using counting sort.
 *
 *  @array: The array to be sorted.
 *
 *  @size: The size of the array to be sorted.
 *
 *  Description: Returns the counting array after setting it up
 */
void counting_sort(int *array, size_t size)
{
	size_t i;
	int max_element = array[0];
	int *count, *count_b;

	if (array == NULL || size < 2)
		return;
	for (i = 1; i < size; i++)
	{
		if (array[i] > max_element)
		max_element = array[i];
	}

	count = (int *)malloc((max_element + 1) * sizeof(int));
	if (count == NULL)
		return;
	count_b = (int *)malloc(size * sizeof(int));
	if (count_b == NULL)
	{
		free(count);
		return;
	}
	for (i = 0; i <= (size_t)max_element; i++)
		count[i] = 0;
	for (i = 0; i < size; i++)
		count[array[i]]++;
	for (i = 1; i <= (size_t)max_element; i++)
		count[i] = count[i] + count[i - 1];
	print_array(count, max_element + 1);
	for (i = size - 1; i != (size_t) -1; i--)
		count_b[--count[array[i]]] = array[i];
	for (i = 0; i < size; i++)
		array[i] = count_b[i];
	free(count);
	free(count_b);
}
