#include "binary_trees.h"
/**
 * binary_tree_uncle - finds the uncle of a node
 *
 * @node: pointer to the node to find the uncle
 *
 * Return: pointer to the uncle node
 */
binary_tree_t *binary_tree_uncle(binary_tree_t *node)
{
	binary_tree_t *parent, *grand_parent;

	if (node == NULL || node->parent == NULL || node->parent->parent == NULL)
		return (NULL);
	parent = node->parent;
	grand_parent = parent->parent;
	if (parent == grand_parent->left && grand_parent->right != NULL)
		return (grand_parent->right);
	else if (parent == grand_parent->right && grand_parent->left != NULL)
		return (grand_parent->left);
	else
		return (NULL);
}
