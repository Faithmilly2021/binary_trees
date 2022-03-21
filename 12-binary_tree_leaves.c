#include "binary_trees.h"

/**
 * binary_tree_leaves - Counts the leaves in a binary tree
 *
 * @tree: Pointer to the root node of the tree to count the leaves
 *
 * Return: Number of leaves or 0 for `NULL` value
 */
size_t binary_tree_leaves(const binary_tree_t *tree)
{
	size_t cnt = 0;

	if (tree)
	{
		cnt += !tree->left && !tree->right ? 1 : 0;
		cnt += binary_tree_leaves(tree->left);
		cnt += binary_tree_leaves(tree->right);
	}
	return (cnt);
}
