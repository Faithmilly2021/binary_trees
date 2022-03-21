#include <stdlib.h>
#include "binary_trees.h"

/**
 * binary_tree_insert_left - Inserts a node as the left-child of another node
 *
 * @parent: Pointer to the node to insert left-child in
 * @value: Value to store in new node
 *
 * Return: Pointer to the created node, or `NULL` on failure
 *         or if parent is NULL
 */
binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
	binary_tree_t *node;

	if (!parent)
		return (parent);

	node = malloc(sizeof(*node));
	if (!node)
		return (node);

	node->n = value;
	node->left = NULL;
	node->right = NULL;

	if (!parent->left)
	{
		node->parent = parent;
		parent->left = node;
	}
	else
	{
		node->left = parent->left;
		node->parent = parent;
		parent->left->parent = node;
		parent->left = node;
	}

	return (parent->left);
}
