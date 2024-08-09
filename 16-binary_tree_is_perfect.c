#include "binary_trees.h"
/**
 * depth - finds the depth of the node
 * @tree: the node to measure the depth
 *
 * Return: depth of the node
 */
int depth(const binary_tree_t *tree)
{
	int depth = 0;

	while (tree)
	{
		depth++;
		tree = tree->left;
	}

	return (depth);
}
/**
 * is_perfect - checks if the tree is perfect
 * @tree: head node of the tree
 * @d: depth of the tree
 * @level: level of the tree
 *
 * Return: 1 if tree is perfect if not 0
 */
int is_perfect(const binary_tree_t *tree, int d, int level)
{
	if (!tree)
		return (1);

	if (!tree->left && !tree->right)
		return (d == level + 1);

	if (tree->left == NULL || tree->right == NULL)
		return (0);

	return (is_perfect(tree->left, d, level + 1) &&
		is_perfect(tree->right, d, level + 1));
}
/**
 * binary_tree_is_perfect - checks if a binary tree is perfect
 * @tree: a pointer to the root node of the tree to check
 *
 * Return: if tree is perfect 1 if not 0
 * or If tree is NULL, your function must return 0
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	int d = depth(tree);

	if (!tree)
		return (0);

	return (is_perfect(tree, d, 0));
}

