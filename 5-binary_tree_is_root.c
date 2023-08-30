#include "binary_trees.h"

/**
 * binary_tree_is_root - ...
 * @node: ...
 * Return: ...
 */

int binary_tree_is_root(const binary_tree_t *node)
{
	if (!node)
		return (0);

	return (node->parent == NULL);
}
