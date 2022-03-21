#include "binary_trees.h"

/**
 * binary_tree_sibling - Find the sibling of a node
 *
 * @node: Pointer to the node to find the sibling
 *
 * Return: `node` or NULL for `NULL` parent or value
 */
binary_tree_t *binary_tree_sibling(binary_tree_t *node)
{
	if (!node || !node->parent)
		return (NULL);
	return (node->n > node->parent->n ? node->parent->left : node->parent->right);
}
