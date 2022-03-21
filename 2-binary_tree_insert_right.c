#include <stdlib.h>
#include "binary_trees.h"

/**
 * binary_tree_insert_right - Inserts as the right-child of another node
 *
 * @parent: Pointer to the node to insert the right-child in
 * @value: Value to store in the new node
 *
 * Return: Pointer to the created node, or `NULL` on failure
 *         or parent is NULL
 */
binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
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

	if (!parent->right)
	{
		node->parent = parent;
		parent->right = node;
	}
	else
	{
		node->parent = parent;
		node->right = parent->right;
		parent->right->parent = node;
		parent->right = node;
	}

	return (parent->right);
}
