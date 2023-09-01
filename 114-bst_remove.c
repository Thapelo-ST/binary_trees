#include "binary_trees.h"

/**
 * bst_find - ...
 * @node: ...
 * Return: ...
 */
bst_t *bst_find(bst_t *node)
{
	bst_t *current = node->right;

	while (current && current->left)
		current = current->left;
	return (current);
}
/**
 * bst_remove - ...
 * @root: ...
 * @value: ...
 * Return: ...
 */

bst_t *bst_remove(bst_t *root, int value)
{
	bst_t *temp, *successor;

	if (!root)
		return (NULL);

	if (value < root->n)
		root->left = bst_remove(root->left, value);
	else if (value > root->n)
		root->right = bst_remove(root->right, value);
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

		successor = bst_find(root);
		root->n = successor->n;
		root->right = bst_remove(root->right, successor->n);
	}

	return (root);
}
