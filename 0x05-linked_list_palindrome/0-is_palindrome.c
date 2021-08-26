#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

/**
 * is_palindrome - check if list is palindrome
 * @head: pointer to top of list
 * Return: 0 if not palindrome, 1 if yes
 */
int is_palindrome(listint_t **head)
{
	if (!*head)
		return (1);
	return (pal_help(head, *head));
}

/**
 * pal_help - helper
 * @left: start
 * @right: end
 * Return: 1 if true, 0 if false
 */
int pal_help(listint_t **left, listint_t *right)
{
	if (!right)
		return (1);
	if (pal_help(left, right->next) && (*left)->n == right->n)
	{
		*left = (*left)->next;
		return (1);
	}
	else
		return (0);
}
