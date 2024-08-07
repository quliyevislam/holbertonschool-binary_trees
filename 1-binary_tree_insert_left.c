#include "binary_trees.h"
#include <stdlib.h>
/**
 * binary_tree_insert_left - inserts a node as the left-child of another node
 * @parent: a pointer to the node to insert the left-child in
 * @value: the value to store in the new node
 *
 * Return: a pointer to the created node,
 * or NULL on failure or if parent is NULL
 */
binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
	binary_tree_t *new_node = malloc(sizeof(binary_tree_t));

	if (!new_node || !parent)
	{	free(new_node);
		return (NULL); }

	new_node->n = value;
	new_node->parent = NULL;
	new_node->left = NULL;
	new_node->right = NULL;

	if (!parent->left)
	{
		parent->left = new_node;
		new_node->parent = parent;
		return (new_node);
	}

	if (parent->left->n > value)
	{
		new_node->right = parent->left;
		parent->left->parent = new_node;
		parent->left = new_node;
		new_node->parent = parent;
		return (new_node);
	}

	else
	{
		new_node->left = parent->left;
		parent->left->parent = new_node;
		parent->left = new_node;
		new_node->parent = parent;
		return (new_node);
	}
}
