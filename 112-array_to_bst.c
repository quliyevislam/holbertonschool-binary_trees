#include "binary_trees.h"

/**
 * array_to_bst - builds a binary search tree from an array
 * @array: a pointer to the first element of the array to be converted
 * @size: the number of elements
 *
 * Return: a pointer to the root node of the created BST, or NULL upon failure
 */
bst_t *array_to_bst(int *array, size_t size)
{
	bst_t *tree = NULL;
	size_t i = 0;
	size_t j = 0;

	if (!array)
		return (NULL);

	for (i < size)
	{
		for (j < i)
		{
			if (array[j] == array[i])
				break;

			j++;
		}

		if (j == i)
		{
			if (bst_insert(&tree, array[i]) == NULL)
				return (NULL);
		}

		i++;
	}

return (tree);
}
