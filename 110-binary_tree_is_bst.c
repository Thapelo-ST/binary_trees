#include "binary_trees.h"

/**
 * is_bst_util - ...
 * @tree: ...
 * @min: ...
 * @max: ...
 * Return: ...
 */

int is_bst_util(const binary_tree_t *tree, int min, int max)
{
	if (!tree)
		return (1);

	if (tree->n <= min || tree->n >= max)
		return (0);

	return (is_bst_util(tree->left, min, tree->n)
			&& is_bst_util(tree->right, tree->n, max));
}

/**
 * binary_tree_is_bst - ...
 * @tree: ...
 * Return: ...
 */

int binary_tree_is_bst(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	return (is_bst_util(tree, INT_MIN, INT_MAX));
}
