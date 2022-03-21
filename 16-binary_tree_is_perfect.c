#include "binary_trees.h"

/**
 * binary_tree_is_perfect - Checks if a binary tree is perfect
 *
 * @tree: Pointer to the root node of the tree to check
 *
 * Return: 0 if not `perfect` or `NULL`, 1 if perfect.
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	if (!tree)
		return (0);
	return (check_tree_if_perfect(tree));
}

/**
 * binary_tree_is_leaf - Checks if a node is a leaf
 *
 * @node: Pointer to the node to check
 *
 * Return: 1 if `node` is a lead, otherwise 0 (and 0 for `NULL` value)
 */
int binary_tree_is_leaf(const binary_tree_t *node)
{
	if (!node || node->left || node->right)
		return (0);
	return (1);
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

/**
 * check_tree_if_perfect - Checks if a binary tree is perfect
 *
 * @tree: Pointer to the root node of the tree to check
 *
 * Return: 0 if not perfect or `NULL`, 1 if tree is perfect
 */
int check_tree_if_perfect(const binary_tree_t *tree)
{
	if (tree)
	{
		if ((!check_tree_if_full(tree->left) || !check_tree_if_full(tree->right))
				|| (binary_tree_is_leaf(tree->left)
					&& !binary_tree_is_leaf(tree->right))
				|| (binary_tree_is_leaf(tree->right)
					&& !binary_tree_is_leaf(tree->left))
				|| !check_tree_if_perfect(tree->left)
				|| !check_tree_if_perfect(tree->right))
			return (0);
	}
	return (1);
}
