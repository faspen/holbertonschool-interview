#include "binary_trees.h"
/**
 * binary_tree_node - create node in tree
 * @parent: pointer to parent of new node
 * @value: number in node
 * Return: pointer to new node, or null
 */

binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
	binary_tree_t *new = NULL;

	new = malloc(sizeof(binary_tree_t));
	if (!new)
		return (NULL);

	new->parent = parent;
	new->left = NULL;
	new->right = NULL;
	new->n = value;
	return (new);
}
