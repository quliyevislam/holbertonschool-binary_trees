#include "binary_trees.h"

/**
 * binary_tree_balance - measures the balance factor of a binary tree
 * @tree: a pointer to the root node of the tree to measure the balance factor
 *
 * Return: balance of the tree or if tree is NULL, return 0
 */
int binary_tree_balance(const binary_tree_t *tree)
{
	int h_left;
	int h_right;

	if (!tree)
		return (0);

	h_left = (int)binary_tree_height(tree->left);
	h_right = (int)binary_tree_height(tree->right);

	return (h_left - h_right);
}
