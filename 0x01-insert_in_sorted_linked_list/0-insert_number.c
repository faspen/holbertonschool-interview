#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "lists.h"

/**
 * insert_node - insert node in sorted list
 * @head: top of list
 * @number: number in node
 * Return: new node, NULL if fail
 */
listint_t *insert_node(listint_t **head, int number)
{
	listint_t *traverse = *head;
	listint_t *tmp = NULL;
	listint_t *node;

	node = malloc(sizeof(listint_t));

	if (!node)
		return (NULL);
	node->n = number;

	if (!*head)
	{
		/* so no head? */
		*head = node;
		return (node);
	}

	if (number < (*head)->n)
	{
		/* smallest number */
		node->next = *head;
		*head = node;
		return (node);
	}

	while (traverse->n < node->n && traverse->next)
	{
		/* speedrun */
		tmp = traverse;
		traverse = traverse->next;
	}
	node->next = traverse;
	tmp->next = node;
	return (node);
}
