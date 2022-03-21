#include "binary_trees.h"

/**
 * binary_tree_nodes - Counts the nodes with at least 1 child in a binary tree
 *
 * @tree: Pointer to the root node of the tree to count the number of nodes
 *
 * Return: Count or 0 for `NULL` value
 */
size_t binary_tree_nodes(const binary_tree_t *tree)
{
	size_t cnt = 0;

	if (tree)
	{
		cnt += (tree->left || tree->right) ? 1 : 0;
		cnt += binary_tree_nodes(tree->left);
		cnt += binary_tree_nodes(tree->right);
	}

	return (cnt);
}
