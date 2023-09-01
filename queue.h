#ifndef QUEUE_H
#define QUEUE_H

#include <stddef.h>
#include "binary_trees.h"

/************** stuctures ***************/

/**
 * struct queue_node - ...
 * @tree_node: ...
 * @next: ...
 */

typedef struct queue_node
{
	const binary_tree_t *tree_node;
	struct queue_node *next;
} queue_node_t;

/**
 * struct queue - ...
 * @front: ...
 * @rear: ...
 */

typedef struct queue
{
	queue_node_t *front;
	queue_node_t *rear;
} queue_t;

/************** functions ***************/

/**
 * queue_create - ...
 * Return: ...
 */
static inline queue_t *queue_create(void)
{
	queue_t *queue = malloc(sizeof(queue_t));

	if(!queue)
		return (NULL);

	queue->front = queue->rear = NULL;
	return (queue);
}

/**
 * queue_push - ...
 * @queue: ...
 * @tree_node: ...
 */
static inline void queue_push(queue_t *queue, const binary_tree_t *tree_node)
{
	queue_node_t *new_node = malloc(sizeof(queue_node_t));

	if (!new_node)
		return;

	new_node->tree_node = tree_node;
	new_node->next = NULL;

	if (!queue->rear)
	{
		queue->front = queue->rear = new_node;
	}
	else
	{
		queue->rear->next = new_node;
		queue->rear = new_node;
	}
}

/**
 * queue_pop - ...
 * @queue: ...
 * Return: ...
 */

static inline const binary_tree_t *queue_pop(queue_t *queue)
{
	const binary_tree_t *tree_node;
	queue_node_t *temp;

	if (!queue->front)
		return (NULL);

	tree_node = queue->front->tree_node;
	temp = queue->front;
	queue->front = queue->front->next;
	free(temp);

	if (!queue->front)
		queue->rear = NULL;
	return (tree_node);
}

/**
 * queue_is_empty - ...
 * @queue: ...
 * Return: ...
 */
static inline int queue_is_empty(const queue_t *queue)
{
	return (queue->front == NULL);
}

/**
 * queue_delete - ...
 * @queue: ...
 */
static inline void queue_delete(queue_t *queue)
{
	while (!queue_is_empty(queue))
	{
		queue_pop(queue);
	}
	free(queue);
}
#endif /* QUEUE_H */
