#include "binary_trees.h"

/**
 * get_height - calculate height of tree
 * @tree: head of tree
 * Return: height of tree
 */
size_t get_height(const heap_t *tree)
{
	size_t l_height, r_height;

	if (!tree || (!tree->left && !tree->right))
		return (0);
	r_height = get_height(tree->right);
	l_height = get_height(tree->left);

	if (r_height > l_height)
		return (r_height + 1);
	else
		return (l_height + 1);
}

/**
 * traverse - travel through a tree
 * @root: pointer to tree's root
 * @node: pointer to node in the tree
 * @height: tree's height
 * @base: base
 */
void traverse(heap_t *root, heap_t **node, size_t height, size_t base)
{
	if (!root)
		return;
	if (height == base)
		*node = root;

	base += 1;

	if (root->left)
		traverse(root->left, node, height, base);
	if (root->right)
		traverse(root->right, node, height, base);
}

/**
 * sort - sort the tree
 * @node: points to root
 * Return: sorted tree
 */
heap_t *sort(heap_t *node)
{
	int num;

	while (node->left || node->right)
	{
		if (!node->right || node->left->n > node->right->n)
		{
			num = node->n;
			node->n = node->left->n;
			node->left->n = num;
			node = node->left;
		}
		else if (!node->left || node->left->n < node->right->n)
		{
			num = node->n;
			node->n = node->right->n;
			node->right->n = num;
			node = node->right;
		}
	}
	return (node);
}


/**
 * heap_extract - extracts root node
 * @root: pointer to said root
 * Return: the node
 */
int heap_extract(heap_t **root)
{
	int val, height, base = 0;

	heap_t *tmp, *node;

	if (!root || !*root)
		return (base);

	tmp = *root;
	val = tmp->n;
	if (!tmp->right && !tmp->left)
	{
		*root = NULL;
		free(tmp);
		return (val);
	}

	height = get_height(tmp);
	traverse(tmp, &node, height, base);
	tmp = sort(tmp);
	tmp->n = node->n;

	if (node->parent->right)
		node->parent->right = NULL;
	else
		node->parent->left = NULL;
	free(node);

	return (val);
}
