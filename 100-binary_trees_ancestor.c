#include "binary_trees.h"
/**
 * binary_trees_ancestor - finds the lowest common ancestor of two nodes
 * @first: a pointer to the first node
 * @second: a pointer to the second node
 *
 * Return: If no common ancestor was found, function returns NULL
 */
binary_tree_t*
binary_trees_ancestor(const binary_tree_t *first, const binary_tree_t *second)
{
	const binary_tree_t *a = first;
	const binary_tree_t *b = second;

	while (a || b)
	{
		if (a == b)
			return ((binary_tree_t *)a);

		if (a)
			a = a->parent;

		else
			a = second;

		if (b)
			b = b->parent;

		else
			b = first;
	}

	return (NULL);
}
