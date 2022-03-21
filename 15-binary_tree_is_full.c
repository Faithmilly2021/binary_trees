#include "binary_trees.h"

/**
 * binary_tree_is_full - Checks if a binary tree is full
 *
 * @tree: Pointer to the root node of the tree to check
 *
 * Return: 0 if not full or `NULL`, 1 if tree is full
 */
int binary_tree_is_full(const binary_tree_t *tree)
{
	if (!tree)
		return (0);
	return (check_tree_if_full(tree));
}

/**
 * check_tree_if_full - Checks if a binary tree is full
 *
 * @tree: Pointer to the root node of the tree to check.
 *
 * Return: 0 if not full or `NULL`, 1 if tree is full
 */
int check_tree_if_full(const binary_tree_t *tree)
{
	if (tree)
	{
		if ((tree->left && !tree->right)
				|| (tree->right && !tree->left)
				|| !check_tree_if_full(tree->left)
				|| !check_tree_if_full(tree->right))
			return (0);
	}
	return (1);
}
