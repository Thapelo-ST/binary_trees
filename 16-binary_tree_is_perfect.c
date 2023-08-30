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
 * binary_tree_size - ...
 * @tree: ...
 * Return: ...
 */

size_t binary_tree_size(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	return (binary_tree_size(tree->left) + 1 + binary_tree_size(tree->right));
}


/**
 * binary_tree_is_perfect - ...
 * @tree: ...
 * Return: ...
 */

int binary_tree_is_perfect(const binary_tree_t *tree)
{
	size_t height, size, is_perfect;

	if (!tree)
		return (0);

	size = binary_tree_size(tree);
	height = binary_tree_height(tree);
	is_perfect = (1 << height) - 1;

	return (size == is_perfect);
}
