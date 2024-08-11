#include "binary_trees.h"
binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree)
{
    tree->parent = tree->right;
    tree->right = tree->right->left;
    tree->parent->parent = NULL;
    tree->parent->left = tree;
    return (tree->parent);
}
