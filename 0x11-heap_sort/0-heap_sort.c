#include "sort.h"

/**
 * swap - swap two values
 * @a: value 1
 * @b: value 2
 */
void swap(int *a, int *b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 * heapify - assisting function
 * @array: array to heapify
 * @n: size
 * @i: value
 */
void heapify(int *array, int n, int i)
{
	int largest = i;
	int left = 2 * i + 1;
	int right = 2 * i + 2;

	if (left < n && array[left] > array[largest])
	{
		largest = left;
	}
	if (right < n && array[right] > array[largest])
	{
		largest = right;
	}
	if (largest != i)
	{
		swap(&array[i], &array[largest]);
		heapify(array, n, largest);
	}
}

/**
 * heap_sort - sort array with heap sort
 * @array: array to sort
 * @size: size of given array
 */
void heap_sort(int *array, size_t size)
{
	int i;

	for (i = size / 2 - 1; i >= 0; i--)
	{
		heapify(array, size, i);
		print_array(array, size);
	}
	for (i = size - 1; i >= 0; i--)
	{
		swap(&array[0], &array[i]);
		heapify(array, i, 0);
		print_array(array, size);

	}
}
