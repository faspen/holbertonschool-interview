#include "lists.h"

/**
 * find_listint_loop - find loop in a linked list
 * @head: head of given list
 * Return: Address of node where loop starts, NULL if none
 */
listint_t *find_listint_loop(listint_t *head)
{
	listint_t *step, *skip;

	if (!head)
		return (NULL);
	step = skip = head;

	while (step && skip && skip->next)
	{
		if (step->next)
			step = step->next;
		if (skip->next && skip->next->next)
			skip = skip->next->next;
		else
			return (NULL);
		if (step == skip)
		{
			step = head;
			while (step && skip && skip->next)
			{
				if (step == skip)
					return (step);
				step = step->next;
				skip = skip->next;
			}
		}
	}
	return (NULL);
}
