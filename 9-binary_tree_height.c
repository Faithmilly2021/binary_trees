#include <stdlib.h>
#include "binary_trees.h"

/**
 * binary_tree_height - Measures the height of a binary tree
 *
 * @tree: Pointer to the root node of the tree to measure the height
 *
 * Return: Height (int) or 0 for `NULL` value
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t t_left, t_right;

	if (!tree)
		return (0);

	t_left = tree->left ? 1 + binary_tree_height(tree->left) : 0;
	t_right = tree->right ? 1 + binary_tree_height(tree->right) : 0;

	return (t_left > t_right ? t_left : t_right);
}
