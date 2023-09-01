#include "binary_trees.h"

/**
 * avl_insert - ...
 * @tree: ...
 * @value: ...
 * Return: ...
 */

avl_t *avl_insert(avl_t **tree, int value)
{
	if (!tree)
		return (NULL);
	if (!*tree)
	{
		*tree = binary_tree_node(NULL, value);
		return (*tree);
	}
	if (value < (*tree)->n)
	{
		(*tree)->left = avl_insert(&(*tree)->left, value);
		if ((*tree)->left)
		{
			(*tree)->left->parent = *tree;
			if (binary_tree_balance(*tree) > 1)
			{
				if (value < (*tree)->left->n)
					*tree = binary_tree_rotate_right(*tree);
				else
				{
					(*tree)->left = binary_tree_rotate_left((*tree)->left);
					*tree = binary_tree_rotate_right(*tree);
				}
			}
		}
	}
	else if (value > (*tree)->n)
	{
		(*tree)->right = avl_insert(&(*tree)->right, value);
		if ((*tree)->right)
		{
			(*tree)->right->parent = *tree;
			if (binary_tree_balance(*tree) < -1)
			{
				if (value > (*tree)->right->n)
					*tree = binary_tree_rotate_left(*tree);
				else
				{
					(*tree)->right = binary_tree_rotate_right((*tree)->right);
					*tree = binary_tree_rotate_left(*tree);
				}
			}
		}
	}
	return (*tree);
}
