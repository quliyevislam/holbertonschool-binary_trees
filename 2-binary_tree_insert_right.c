#include "binary_trees.h"
#include <stdlib.h>

/**
 * binary_tree_insert_right - inserts a node as the right-child of another node
 * @parent: a pointer to the node to insert the right-child in
 * @value: the value to store in the new node
 *
 * Return: a pointer to the created node,
 * or NULL on failure or if parent is NULL
 */
binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
{
	binary_tree_t *new_node = malloc(sizeof(binary_tree_t));

	if (!new_node || !parent)
	{
		free(new_node);
		return (NULL);
	}

	new_node->n = value;
	new_node->parent = NULL;
	new_node->left = NULL;
	new_node->right = NULL;

	if (!parent->right)
	{
		parent->right = new_node;
		new_node->parent = parent;
		return (new_node);
	}

	new_node->right = parent->right;
	parent->right->parent = new_node;
	parent->right = new_node;
	new_node->parent = parent;

	return (new_node);
}
