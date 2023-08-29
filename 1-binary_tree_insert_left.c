#include "binary_trees.h"
/**
 * binary_tree_insert_left - function that inserts a node as the left-child of another node
 *
 * @parent: is a pointer to the node to insert the left-child in
 * @value: is the value to store in the new node
 *
 * Return: newly inserted node
 */
binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
	binary_tree_t *tree_node;

	if (parent == NULL)
		return (NULL);
	tree_node = binary_tree_node(parent, value);
	if (tree_node == NULL)
		return (NULL);
	if (parent->left != NULL)
	{
		parent->left->parent = tree_node;
		tree_node->left = parent->left;
	}
	parent->left = tree_node;
	return (tree_node);
}
