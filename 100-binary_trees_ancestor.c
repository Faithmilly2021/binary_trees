#include "binary_trees.h"

/**
 * binary_trees_ancestor - Finds the lowest common ancestor of two nodes
 *
 * @first: Pointer to the first node
 * @second: Pointer to the second node
 *
 * Return: Pointer to the lowest common ancestor node or NULL if none
 */
binary_tree_t *binary_trees_ancestor(
		const binary_tree_t *first, const binary_tree_t *second)
{
	binary_tree_t *tmp;
	int first_dp, second_dp;

	if (!first || !second)
		return (NULL);

	if (first == second)
		return ((binary_tree_t *)first);

	if ((first == second->parent) || (check_node_is_ancestor(
					(binary_tree_t *)first, (binary_tree_t *)second)))
		return ((binary_tree_t *)first);
	else if ((second == first->parent) || (check_node_is_ancestor(
				(binary_tree_t *)second, (binary_tree_t *)first)))
		return ((binary_tree_t *)second);

	first_dp = binary_tree_depth(first);
	second_dp = binary_tree_depth(second);

	if (first_dp >= second_dp)
	{
		tmp = second->parent;
		while (tmp)
		{
			if (check_node_is_ancestor(tmp, (binary_tree_t *)first))
				return (tmp);
			tmp = tmp->parent;
		}
		return (NULL);
	}

	tmp = first->parent;
	while (tmp)
	{
		if (check_node_is_ancestor(tmp, (binary_tree_t *)second))
			return (tmp);
		tmp = tmp->parent;
	}
	return (NULL);
}


/**
 * binary_tree_depth - Measures the depth of a node in a binary tree
 *
 * @tree: Pointer to the node to measure the depth
 *
 * Return: Height or 0 for `NULL` value
 */
size_t binary_tree_depth(const binary_tree_t *tree)
{
	if (!tree)
		return (0);
	return (tree->parent ? 1 + binary_tree_depth(tree->parent) : 0);
}


/**
 * check_node_is_ancestor - Checks if a node is ancestor
 *
 * @node: Pointer to the node to check if ancestor
 * @child: Pointer to check if @node is ancestor
 *
 * Return: Pointer to node if ancestor, or NULL if not
 */
binary_tree_t *check_node_is_ancestor(binary_tree_t *node,
		binary_tree_t *child)
{
	if (node && child)
	{
		if ((node->left == child || node->right == child)
				|| check_node_is_ancestor(node->left, child)
				|| check_node_is_ancestor(node->right, child))
			return (node);
	}
	return (NULL);
}
