#include "binary_trees.h"

/**
 * binary_tree_is_complete - ...
 * @tree: ...
 * Return: ...
 */

int binary_tree_is_complete(const binary_tree_t *tree)
{
	int is_complete = 1, null_index = 0, queue_size = 0, i;
	binary_tree_t **queue = malloc(sizeof(binary_tree_t *));
	binary_tree_t *current;

	if (!tree)
		return (0);

	if (!queue)
		return (0);
	queue[queue_size++] = (binary_tree_t *)tree;
	while (queue_size > 0)
	{
		current = queue[0];

		if (!current)
		{
			null_index = 1;
		}
		else
		{
			if (null_index)
			{
				is_complete = 0;
				break;
			}
			queue = realloc(queue, sizeof(binary_tree_t *) * queue_size * 2);
			if (!queue)
				return (0);
			queue[queue_size++] = current->left;
			queue[queue_size++] = current->right;
		}
		for (i = 0; i < queue_size - 1; i++)
			queue[i] = queue[i + 1];
		queue_size--;
	}
	free(queue);
	return (is_complete);
}
