#include "lists.h"

/**
 * check_cycle - check if linked list has a cycle
 * @list: list to check
 * Return: 0 if not cycle, 1 if cycle
 */

int check_cycle(listint_t *list)
{
	listint_t *test1 = list;
	listint_t *test2 = list;

	if (list == NULL)
		return (0);

	while (test1 && test1->next)
	{
		test1 = test1->next->next;
		test2 = test2->next;

		if (test1 == test2)
			return (1);
	}
	return (0);
}
