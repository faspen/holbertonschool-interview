#include "binary_trees.h"

/**
 * createNode - create node for the tree
 * @parent: parent node for new node
 * @n: value
 * Return: node
 */
avl_t *createNode(avl_t *parent, size_t n)
{
	avl_t *node;

	node = malloc(sizeof(avl_t));
	if (!node)
		return (NULL);

	node->n = n;
	node->left = NULL;
	node->right = NULL;
	node->parent = parent;

	return (node);
}

/**
 * createTree - convert array to tree
 * @array: array to convert
 * @start: start of tree
 * @end: end of tree
 * @parent: parent node
 * Return: root node
 */
avl_t *createTree(int *array, size_t start, size_t end, avl_t *parent)
{
	size_t mid;
	avl_t *root;

	if (start > end)
		return (NULL);

	mid = (start + end) / 2;

	root = createNode(parent, array[mid]);

	if (!root)
		return (NULL);
	if (start != mid)
		root->left = createTree(array, start, mid - 1, root);
	if (end != mid)
		root->right = createTree(array, mid + 1, end, root);
	return (root);
}

/**
 * sorted_array_to_avl - build avl tree from array
 * @array: pointer to first element of array
 * @size: size of the array
 * Return: pointer to root node of tree, NULL on fail
 */
avl_t *sorted_array_to_avl(int *array, size_t size)
{
	avl_t *root;

	if (!array)
		return (NULL);

	return (root = createTree(array, 0, size - 1, NULL));
}
