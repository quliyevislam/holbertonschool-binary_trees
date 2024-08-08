#include "binary_trees.h"

/**
 * binary_tree_inorder - goes through a binary tree using in-order traversal
 * @tree: a pointer to the root node of the tree to traverse
 * @func:  a pointer to a function to call for each node
 */
void binary_tree_inorder(const binary_tree_t *tree, void (*func)(int))
{
	if (!tree)
		return;

	(*func)(tree->n);
	binary_tree_inorder(tree->left, &print_num);
	binary_tree_inorder(tree->right, &print_num);
}
