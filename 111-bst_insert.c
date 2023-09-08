#include "binary_trees.h"
/**
 * help_insert - insert node into bst helper function
 *
 * @tree: pointer to root of tree
 * @value: value of node passed
 * @parent: parent of node passed
 *
 * Return: node inserted
 */
bst_t *help_insert(bst_t **tree, int value, bst_t *parent)
{
	bst_t *node = NULL;

	if (*tree == NULL)
	{
		node = binary_tree_node(NULL, value);
		node->parent = parent;
		*tree = node;
		return (node);
	}
	if (value == (*tree)->n)
		return (NULL);
	if (value < (*tree)->n)
		return (help_insert(&(*tree)->left, value, *tree));
	else
		return (help_insert(&(*tree)->right, value, *tree));
}
/**
 * bst_insert - insert node into bst helper function
 *
 * @tree: pointer to root of tree
 * @value: value of node passed
 *
 * Return: node inserted
 */
bst_t *bst_insert(bst_t **tree, int value)
{
	return (help_insert(&(*tree), value, NULL));
}
