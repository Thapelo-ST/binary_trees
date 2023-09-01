#include "binary_trees.h"

/**
 * sorted_array_to_avl - ...
 * @array: ...
 * @size: ...
 * Return: ...
 */
avl_t *sorted_array_to_avl(int *array, size_t size)
{
	if (!array || size == 0)
		return (NULL);

	return (sorted_array_to_avl_helper(array, 0, size - 1, NULL));
}

/**
 * sorted_array_to_avl_helper - ...
 * @array: ...
 * @start: ...
 * @end: ...
 * @parent: ...
 * Return: ...
 */
avl_t *sorted_array_to_avl_helper(int *array, size_t start,
								  size_t end, avl_t *parent)
{
	size_t mid;
	avl_t *new_node;

	if (start > end)
		return (NULL);

	mid = (start + end) / 2;

	new_node = binary_tree_node(parent, array[mid]);
	if (!new_node)
		return (NULL);

	new_node->left = sorted_array_to_avl_helper(array, start, mid - 1, new_node);
	new_node->right = sorted_array_to_avl_helper(array, mid + 1, end, new_node);

	return (new_node);
}
