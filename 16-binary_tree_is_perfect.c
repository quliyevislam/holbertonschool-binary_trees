#include "binary_trees.h"

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

int is_balance(const binary_tree_t *tree)
{
int h_left;
int h_right;
if (!tree)
return (0);
h_left = binary_tree_h(tree->left);
h_right = binary_tree_h(tree->right);
return (h_left - h_right);
}

int is_full(const binary_tree_t *tree)
{
if (tree == NULL)
return (0);
if (tree->left == NULL && tree->right == NULL)
return (1);
if ((tree->left) && (tree->right))
return (is_full(tree->left) && is_full(tree->right));
return (0);
}

int binary_tree_is_perfect(const binary_tree_t *tree)
{
if (!tree)
return (0);
return (is_full(tree) && !is_balance(tree) ? 1 : 0);
}
