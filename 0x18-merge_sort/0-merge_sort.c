#include "sort.h"

/**
 * merge_helper - sort subs
 * @copy: copy array
 * @array: original
 * @start: start point
 * @mid: midpoint
 * @end: end point
 */
void merge_helper(int *array, int start, int mid, int end, int *copy)
{
	int i = 0, j = 0, x = 0;

	i = start, j = mid, x = start;

	while (x < end)
	{
		if (i < mid && (j >= end || array[i] <= array[j]))
		{
			copy[x] = array[i];
			i++;
		}
		else
		{
			copy[x] = array[j];
			j++;
		}
		x++;
	}
}

/**
 * merge_split - split the array
 * @copy: array copy
 * @start: starting point
 * @end: ending point
 * @array: the array
 */
void merge_split(int *copy, size_t start, size_t end, int *array)
{
	size_t middle = 0;

	if (end - start <= 1)
		return;
	middle = (end + start) / 2;

	merge_split(array, start, middle, copy);
	merge_split(array, middle, end, copy);
	merge_helper(copy, start, middle, end, array);
	printf("Merging...\n");
	printf("[left]: ");
	print_array(&(copy[start]), middle - start);
	printf("[right]: ");
	print_array(&(copy[middle]), end - middle);
	printf("[Done]: ");
	print_array(&(array[start]), end - start);
}

/**
 * _strcpy - copy string
 * @array: old array
 * @copy: new array
 * @size: length
 */
void _strcpy(int *array, int *copy, size_t size)
{
	size_t i = 0;

	while (i < size)
	{
		copy[i] = array[i];
		i++;
	}
}

/**
 * merge_sort - sort an array with merge sort
 * @array: array to sort
 * @size: size of the array
 */
void merge_sort(int *array, size_t size)
{
	int *copy = NULL;

	copy = malloc(sizeof(int) * size);
	if (!copy)
		return;
	_strcpy(array, copy, size);
	merge_split(copy, 0, size, array);
	free(copy);
}
