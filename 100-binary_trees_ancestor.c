#include "binary_trees.h"

binary_tree_t
*binary_trees_ancestor(const binary_tree_t *first, const binary_tree_t *second)
{
	const binary_tree_t *first_copy = first;
	const binary_tree_t *second_copy = second;

	while (first_copy)
	{
		if (first_copy == second_copy)
			return (NULL);

		first_copy = first_copy->parent;
	}

	first_copy = first;

	while (second_copy)
	{
		if (second_copy == first_copy)
			return (NULL);

		second_copy = second_copy->parent;
	}

	second_copy = second;

	while (first)
	{
		first = first->parent;

		while (second)
		{
			second = second->parent;

			if (first == second)
				return ((binary_tree_t *)first);
		}
	}

	return (NULL);
}
