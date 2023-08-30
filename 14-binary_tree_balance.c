#include "binary_trees.h"

/**
 * binary_tree_height - ...
 * @tree: ...
 * Return: ...
 */

size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t left_height = 0, right_height = 0;

	if (!tree)
		return (0);

	left_height = binary_tree_height(tree->left);
	right_height = binary_tree_height(tree->right);

	return (((left_height > right_height) ? left_height : right_height) + 1);
}


/**
 * binary_tree_balance - ...
 * @tree: ...
 * Return: ...
 */

int binary_tree_balance(const binary_tree_t *tree)
{
	int left_height, right_height;

	if (!tree)
		return (0);

	left_height = (int)binary_tree_height(tree->left);
	right_height = (int)binary_tree_height(tree->right);

	return (left_height - right_height);
}
