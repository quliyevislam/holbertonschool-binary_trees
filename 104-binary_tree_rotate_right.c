#include "binary_trees.h"
/**
 * binary_tree_rotate_right - performs a right-rotation on a binary tree
 * @tree:  a pointer to the root node of the tree to rotate
 *
 * Return: a pointer to the new root node of the tree once rotated
 */
binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree)
{
	if (!tree)
		return (NULL);

	tree->parent = tree->left;
	tree->left = tree->left->right;
	tree->parent->parent = NULL;
	tree->parent->right = tree;
	return (tree->parent);
}
