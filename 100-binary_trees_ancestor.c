#include "binary_trees.h"
/**
 * check_len - checks list length
 *
 * @list: list passed
 *
 * Return: list length
 */
int check_len(binary_tree_t **list)
{
	int i = 0;

	while (list[i] != NULL)
		i++;

	return (i);
}
/**
 * binary_trees_ancestor - finds the lowest common ancestor of two nodes
 *
 * @first: first node passed
 * @second: socend node passed
 *
 * Return: Pointer to the ancestor
 */
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
		const binary_tree_t *second)
{
	int i, l1, l2, y;
	const binary_tree_t *node;
	binary_tree_t *list[10] = {NULL}, *list2[10] = {NULL};

	if (first == NULL || second == NULL)
		return (NULL);
	node = first, i = 0;
	while (node != NULL)
	{
		list[i] = (binary_tree_t *)node;
		node = node->parent, i++;
	}
	list[i] = NULL, node = second->parent, i = 0;
	while (node != NULL)
	{
		list2[i] = (binary_tree_t *)node, node = node->parent, i++;
	}
	l1 = check_len(list), l2 = check_len(list2);
	if (l1 > l2)
	{
		for (i = 0; i < l1; i++)
		{
			for (y = 0; y < l2; y++)
			{
				if (list[i] == list2[y])
					return (list[i]);
			}
		}
	} else
	{
		for (i = 0; i < l1; i++)
		{
			for (y = 0; y < l2; y++)
			{
				if (list[i] == list2[y])
					return (list[i]);
			}
		}
	}
	return (NULL);
}
