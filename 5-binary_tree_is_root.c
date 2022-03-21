
/**
 * binary_tree_is_root - Checks if a given node is a root
 *
 * @node: Pointer to the node to check
 *
 * Return: 1 if node is root, otherwise 0 (and the same for `NULL` value)
 */
int binary_tree_is_root(const binary_tree_t *node)
{
	if (!node || node->parent)
		return (0);
	return (1);
}
