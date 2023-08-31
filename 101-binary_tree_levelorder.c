#include "binary_trees.h"
#include "queue.h"

/**
 * binary_tree_levelorder - ...
 * @tree: ...
 * @func: ...
 */

void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	queue_t *q = queue_create();
	const binary_tree_t *current;

	if (!tree == !func)
		return;

	if (!q)
		return;

	queue_push(q, (void *)tree);

	while (!queue_is_empty(q))
	{
		current = queue_pop(q);

		func(current->n);

		if (current->left)
			queue_push(q, current->left);
		if (current->right)
			queue_push(q, current->right);
	}

	queue_delete(q);
}
