#include "binary_trees.h"
int depth(binary_tree_t  *node) {
  int d = 0;
  while (node != NULL) {
    d++;
    node = node->left;
  }
  return d;
}

int is_perfect(binary_tree_t *tree, int d, int level) {

  if (tree == NULL)
    return (1);

 if (tree->left == NULL && tree->right == NULL)
    return (d == level + 1);

  if (tree->left == NULL || tree->right == NULL)
    return (0);

  return is_perfect(tree->left, d, level + 1) &&
       is_perfect(tree->right, d, level + 1);
}

int binary_tree_is_perfect( binary_tree_t *tree)
{

  int d = depth(tree);
  return is_perfect(tree, d, 0);
}

