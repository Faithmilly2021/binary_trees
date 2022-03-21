#include "binary_trees.h"

/**
 * binary_tree_size - Measures the size of a binary tree
 *
 * @tree: Pointer to the root node of the tree to measure the size
 *
 * Return: Size or 0 for `NULL` value
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	size_t value = 0;

	if (tree)
	{
		value += 1;
		value += binary_tree_size(tree->left);
		value += binary_tree_size(tree->right);
	}
	return (value);
}
