#include "binary_trees.h"

/**
 * binary_tree_rotate_left - ...
 * @tree: ...
 * Return: ...
 */

binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree)
{
	binary_tree_t *new_root = NULL;

	if (!tree || !tree->right)
		return (NULL);

	new_root = tree->right;
	tree->right = new_root->left;

	if (new_root->left)
		new_root->left->parent = tree;

	new_root->parent = tree->parent;

	if (tree->parent)
	{
		if (tree->parent->left == tree)
			tree->parent->left = new_root;
		else
			tree->parent->right = new_root;
	}

	new_root->left = tree;
	tree->parent = new_root;

	return (new_root);
}
