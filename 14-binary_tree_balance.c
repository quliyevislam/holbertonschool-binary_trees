#include "binary_trees.h"

/**
 * binary_tree_h - measures the height of a binary tree
 * @tree: a pointer to the root node of the tree to measure the height
 *
 * Return: height of the tree or If tree is NULL, your function must return 0
 */
int binary_tree_h(const binary_tree_t *tree)
{
	int left_height, right_height;

	if (!tree)
		return (0);

	left_height = binary_tree_h(tree->left);
	right_height = binary_tree_h(tree->right);

	if (left_height > right_height)
		return (left_height + 1);

	else
		return (right_height + 1);
}

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

	h_left = binary_tree_h(tree->left);
	h_right = binary_tree_h(tree->right);

	return (h_left - h_right);
}
