#include "binary_trees.h"
/**
 * binary_tree_node - function that creates a binary tree node
 *
 * @parent: pointer to the parent node of the node to create
 * @value: value passed, so the node can hold
 *
 * Return: tree node created
 */
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
	binary_tree_t *tree_node;

	tree_node = malloc(sizeof(binary_tree_t));
	if (tree_node == NULL)
		return (NULL);
	tree_node->parent = parent;
	tree_node->left = NULL;
	tree_node->right = NULL;
	tree_node->n = value;
	return (tree_node);
}
