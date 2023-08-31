#include "binary_trees.h"

/**
 * binary_trees_ancestor - ...
 * @first: ...
 * @second: ...
 * Return: ...
 */

binary_tree_t *binary_trees_ancestor(const binary_tree_t *first, const
									 binary_tree_t *second)
{
	const binary_tree_t *ptr1, *ptr2;

	if (!first || !second)
		return (NULL);

	ptr1 = first;
	while (ptr1)
	{
		ptr2 = second;
		while (ptr2)
		{
			if (ptr1 == ptr2)
				return ((binary_tree_t *)ptr1);
			ptr2 = ptr2->parent;
		}
		ptr1 = ptr1->parent;
	}

	return (NULL);
}
