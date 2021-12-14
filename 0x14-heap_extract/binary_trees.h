#ifndef TREES_H
#define TREES_H

/* Libraries */
#include <stdio.h>
#include <stdlib.h>


/* Prototypes */


/**
 * struct binary_tree_s - Binary tree node
 *
 * @n: Integer stored in the node
 * @parent: Pointer to the parent node
 * @left: Pointer to the left child node
 * @right: Pointer to the right child node
 */
struct binary_tree_s
{
	int n;
	struct binary_tree_s *parent;
	struct binary_tree_s *left;
	struct binary_tree_s *right;
};

typedef struct binary_tree_s binary_tree_t;
typedef struct binary_tree_s heap_t;

int heap_extract(heap_t **root);
void binary_tree_print(const heap_t *tree);
size_t get_height(const heap_t *tree);
void traverse(heap_t *root, heap_t **node, size_t height, size_t base);
heap_t *sort(heap_t *node);


#endif
