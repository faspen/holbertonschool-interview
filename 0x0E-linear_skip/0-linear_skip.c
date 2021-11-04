#include "search.h"


/**
 * linear_skip - search for value in sorted skip list
 * @list: pointer to head of the list
 * @value: value to search for
 * Return: pointer to value node
 */
skiplist_t *linear_skip(skiplist_t *list, int value)
{
	skiplist_t *curr;
	skiplist_t *prev;
	char *finder = "Value checked at index";
	char *found = "Value found between index";

	if (!list)
		return (NULL);
	prev = list;
	curr = list->express;

	while (curr)
	{
		printf("%s [%lu] = [%d]\n", finder, curr->index, curr->n);
		if (curr->n >= value)
			break;
		prev = curr;
		if (!curr->express)
		{
			while (curr->next)
				curr = curr->next;
			break;
		}
		curr = curr->express;
	}
	printf("%s [%lu] and [%lu]\n", found, prev->index, curr->index);
	while (prev && prev->index <= curr->index)
	{
		printf("%s [%lu] = [%d]\n", finder, curr->index, curr->n);
		if (prev->n == value)
			return (prev);
		prev = prev->next;
	}
	return (NULL);
}
