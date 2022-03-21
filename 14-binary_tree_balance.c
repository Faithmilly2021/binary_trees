#include "binary_trees.h"

/**
 * binary_tree_balance - Measures the balance factor of a binary tree
 *
 * @tree: Pointer to the root node of the tree to measure the balance factor
 *
 * Return: Factor or 0 for `NULL` value
 */
int binary_tree_balance(const binary_tree_t *tree)
{
	if (tree)
		return (binary_tree_height(tree->left) - binary_tree_height(tree->right));
	return (0);
}

/**
 * binary_tree_height - Measures the height of a binary tree
 *
 * @tree: Pointer to the node to measures the height
 *
 * Return: The height of the tree starting at @tree
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t height_l = 0, height_r = 0;

	if (tree)
	{
		height_l = tree->left ? 1 + binary_tree_height(tree->left) : 1;
		height_r = tree->right ? 1 + binary_tree_height(tree->right) : 1;
	}

	return ((height_l > height_r) ? height_l : height_r);
}
