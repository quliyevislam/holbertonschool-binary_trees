#include "binary_trees.h"

/**
 * tree_height - returns the height of the tree
 * @tree: a pointer to the tree
 *
 * Return: height of the tree
 */
int tree_height(const binary_tree_t *tree)
{
	int left_h;
	int right_h;

	if (!tree)
		return (0);

	else
	{
		left_h = tree_height(tree->left);
		right_h = tree_height(tree->right);

		if (left_h > right_h)
			return (left_h + 1);

		else
			return (right_h + 1);
	}
}

/**
 * printCurrentLevel - prints the all the nodes in current level
 * @tree: a pointer to the tree
 * @level: level to print
 * @func: a pointer to a function to print
 */
void
print_current_level(const binary_tree_t *tree, int level, void (*func)(int))
{
	if (!tree)
		return;

	if (level == 1)
		(*func)(tree->n);

	else if (level > 1)
	{
		print_current_level(tree->left, level - 1, func);
		print_current_level(tree->right, level - 1, func);
	}
}

/**
 * binary_tree_levelorder -  goes through a binary tree
 * using level-order traversal
 * @tree: a pointer to the root node of the tree to traverse
 * @func: a pointer to a function to call for each node
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	int height = tree_height(tree);
	int i = 1;

	if (!tree || !func)
		return;

	while (i <= height)
	{
		print_current_level(tree, i, func);
		i++;
	}
}
