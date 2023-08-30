#include "binary_trees.h"
/**
 * binary_tree_nodes - counts the nodes with at least 1 child
 *
 * @tree: pointer to the root node of the tree
 *
 * Return: the number of nodes
 */
size_t binary_tree_nodes(const binary_tree_t *tree)
{
	size_t right = 0, left = 0;

	if (tree == NULL)
		return (0);

	left = binary_tree_nodes(tree->left);
	right = binary_tree_nodes(tree->right);
	if (tree->left != NULL || tree->right != NULL)
		return (1 + left + right);
	return (left + right);
}
