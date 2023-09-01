#include "binary_trees.h"

/**
 * binary_tree_min - ...
 * @tree: ...
 * Return: ...
 */

binary_tree_t *binary_tree_min(const binary_tree_t *tree)
{
	if (!tree)
		return (NULL);

	while (tree->left)
		tree = tree->left;

	return ((binary_tree_t *)tree);
}

/**
 * avl_remove - ...
 * @root: ...
 * @value: ...
 * Return: ...
 */
avl_t *avl_remove(avl_t *root, int value)
{
	avl_t *temp;
	int balance;

	if (!root)
		return (NULL);

	if (value < root->n)
	{
		root->left = avl_remove(root->left, value);
		if (root->left)
			root->left->parent = root;
	}
	else if (value > root->n)
	{
		root->right = avl_remove(root->right, value);
		if (root->right)
			root->right->parent = root;
	}
	else
	{
		if (!root->left)
		{
			temp = root->right;
			free(root);
			return (temp);
		}
		else if (!root->right)
		{
			temp = root->left;
			free(root);
			return (temp);
		}

		temp = binary_tree_min(root->right);
		root->m = temp->n;
		root->right = avl_remove(root->right, temp->n);
		if (root->right)
			root->right->parent = root;
	}

	balance = binary_tree_balance(root);

	if (balance > 1 && binary_tree_balance(root->left) >= 0)
		return (binary_tree_rotate_right(root));

	if (balance > 1 && binary_tree_balance(root->left) < 0)
	{
		root->left = binary_tree_rotate_left(root->left);
		return (binary_tree_rotate_right(root));
	}

	if (balance < -1 && binary_tree_balance(root->right) <= 0)
		return (binary_tree_rotate_left(root));

	if (balance < -1 && binary_tree_balance(root->right) > 0)
	{
		root->left = binary_tree_rotate_right(root->right);
		return (binary_tree_rotate_left(root));
	}
}
