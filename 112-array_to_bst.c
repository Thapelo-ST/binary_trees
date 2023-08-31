#include "binary_trees.h"

/**
 * array_to_bst - ...
 * @array: ...
 * @size: ...
 * Return: ...
 */

bst_t *array_to_bst(int *array, size_t size)
{
	bst_t *root = NULL;
	size_t i;

	if (!array || size == 0)
		return (NULL);

	for (i = 0; i < size; i++)
	{
		if (bst_insert(&root, array[i]) == NULL)
			return (NULL);
	}
	return (root);
}
