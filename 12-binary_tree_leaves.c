#include "binary_trees.h"
/**
 * binary_tree_leaves - counts the leaves in a binary tree
 *
 * @tree: pointer to the root node of the tree
 *
 * Return: the number of leaves
 */
size_t binary_tree_leaves(const binary_tree_t *tree)
{
	size_t right, left;

	if (tree == NULL)
		return (0);
	left = binary_tree_leaves(tree->left);
	right = binary_tree_leaves(tree->right);
	if (tree->left == NULL && tree->right == NULL)
		return (1);
	return (right + left);
}
