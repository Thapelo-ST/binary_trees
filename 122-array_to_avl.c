#include "binary_trees.h"

/**
 * array_to_avl - ...
 * @array: ...
 * @size: ...
 * Return: ...
 */

avl_t *array_to_avl(int *array, size_t size)
{
	avl_t *root = NULL;
	size_t i;

	if (!array)
		return (NULL);

	for (i = 0; i < size; i++)
	{
		if (avl_insert(&root, array[i]) == NULL)
		{
			return (NULL);
		}
	}
	return (root);
}
