#include "binary_trees.h"

/**
 * create_queue_node - Allocates and initializes a new node for the queue.
 * @node: The binary tree node to be stored in the new queue node.
 *
 * Return: A pointer to the newly created queue node
 * or NULL if allocation fails.
 */
levelorder_queue_t *create_queue_node(binary_tree_t *node)
{
	levelorder_queue_t *new_node;

	new_node = malloc(sizeof(levelorder_queue_t));

	if (!new_node)
		return (NULL);

	new_node->node = node;
	new_node->next = NULL;

	return (new_node);
}

/**
 * free_queue - Releases all nodes in the queue.
 * @head: A pointer to the first node in the queue.
 */
void free_queue(levelorder_queue_t *head)
{
	levelorder_queue_t *current;

	while (head)
	{
		current = head->next;
		free(head);
		head = current;
	}
}

/**
 * enqueue - Adds a binary tree node to the end of the queue.
 * @node: The binary tree node to be added to the queue.
 * @front: A pointer to the front node of the queue.
 * @rear: A double pointer to the rear node of the queue
 * which will be updated.
 *
 * Description: Exits with a status code of 1 if memory allocation fails.
 */
void enqueue(binary_tree_t *node, levelorder_queue_t *front,
levelorder_queue_t **rear)
{
	levelorder_queue_t *new_node;

	new_node = create_queue_node(node);

	if (!new_node)
	{
		free_queue(front);
		exit(1);
	}

	(*rear)->next = new_node;
	*rear = new_node;
}

/**
 * dequeue - Removes the front node from the queue.
 * @front: A double pointer to the front node of the queue
 * which will be updated.
 */
void dequeue(levelorder_queue_t **front)
{
	levelorder_queue_t *current;

	current = (*front)->next;
	free(*front);
	*front = current;
}

/**
 * binary_tree_is_complete - Determines if a binary tree is complete.
 * @tree: A pointer to the root of the binary tree to be checked.
 *
 * Return: 1 if the tree is complete, 0 otherwise
 * Returns 0 if the tree is NULL.
 *
 * Description: Exits with a status code of 1 if memory allocation fails.
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
	levelorder_queue_t *front, *rear;
	unsigned char found_gap = 0;

	if (!tree)
		return (0);

	front = rear = create_queue_node((binary_tree_t *)tree);
	if (!front)
		exit(1);
	while (front)
	{
		if (front->node->left)
		{
			if (found_gap == 1)
			{
				free_queue(front);
				return (0);
			}

			enqueue(front->node->left, front, &rear);
		}
		else
			found_gap = 1;
		if (front->node->right)
		{
			if (found_gap == 1)
			{
				free_queue(front);
				return (0);
			}
			enqueue(front->node->right, front, &rear);
		}
		else
			found_gap = 1;
			dequeue(&front);
	}
	return (1);
}

