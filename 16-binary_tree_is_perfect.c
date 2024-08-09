#include "binary_trees.h"

int depth(const binary_tree_t  *tree)
{
int depth = 0;
while (tree)
{
depth++;
tree = tree->left;
}
return depth;
}

int is_perfect(const binary_tree_t *tree, int d, int level)
{
if (!tree)
return (1);
if (!tree->left && !tree->right)
return (d == level + 1);
if (tree->left == NULL || tree->right == NULL)
return (0);
return is_perfect(tree->left, d, level + 1) &&
is_perfect(tree->right, d, level + 1);
}
int binary_tree_is_perfect(const binary_tree_t *tree)
{
if (!tree)
return (0);
int d = depth(tree);
return is_perfect(tree, d, 0);
}

