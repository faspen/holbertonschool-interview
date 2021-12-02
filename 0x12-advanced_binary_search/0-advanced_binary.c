#include "search_algos.h"

/**
 * finder - helper function
 * @array: array to search
 * @min: minimum value for search
 * @max: maximum value for search
 * @value: value to find
 * Return: value and index
 */
int finder(int *array, int min, int max, int value)
{
	int mid, x;

	if (min > max)
		return (-1);

	printf("Searching in array: ");
	for (x = min; x <= max; x++)
	{
		printf("%d", array[x]);
		if (x != max)
			printf(", ");
		else
			printf("\n");
	}

	if (min == max && array[max] == value)
		return (max);
	if (min == max && array[max] != value)
		return (-1);

	mid = min + (max - min) / 2;

	if ((mid == min || value != array[mid - 1]) && array[mid] == value)
		return (mid);
	if (array[mid] >= value)
		return (finder(array, min, mid, value));
	return (finder(array, mid + 1, max, value));
}

/**
 * advanced_binary - search array for value
 * @array: array to search
 * @size: number of elements
 * @value: value to find
 * Return: value and its index
 */
int advanced_binary(int *array, size_t size, int value)
{
	if (!array || size == 0)
		return (-1);
	return (finder(array, 0, size - 1, value));
}
