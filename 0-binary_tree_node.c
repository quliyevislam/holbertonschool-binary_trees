#include "binary_trees.h"
#include <stdlib.h>

/**
 * binary_tree_node - creates a binary tree node
 * @parent: a pointer to the parent node of the node to create
 * @value: the value to put in the new node
 *
 * Return:  a pointer to the new node, or NULL on failure
 */
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
	struct binary_tree_s *new_node = malloc(sizeof(struct binary_tree_s));

	if (!new_node)
		return (NULL);

	new_node->n = value;
	new_node->left = NULL;
	new_node->right = NULL;
	new_node->parent = NULL;

	if (!parent)
		return (new_node);

	if (parent->n > value)
	{
		parent->left = new_node;
		new_node->parent = parent;
		return (new_node);
	}

	else
	{
		parent->right = new_node;
		new_node->parent = parent;
		return (new_node);
	}
}
