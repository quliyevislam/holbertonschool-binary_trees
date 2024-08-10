binary_tree_t *binary_trees_ancestor(const binary_tree_t *first, const binary_tree_t *second)
{
while (a || b)
    {
        if (a == b)
            return (binary_tree_t *)a;

                if (a)
            a = a->parent;
        else
            a = second;

        if (b)
            b = b->parent;
        else
            b = first;
    }

    return NULL;
}
