#include "binary_trees.h"
/**
 * binary_tree_height - measures the height of a binary tree
 *
 * @tree: pointer to the root node of the tree
 *
 * Return:  the height
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	int counter_right = 0, counter_left = 0;

	if (tree == NULL || (tree->left == NULL && tree->right == NULL))
		return (0);
	counter_left = binary_tree_height(tree->left);
	counter_right = binary_tree_height(tree->right);
	if (counter_left > counter_right)
		return (counter_left + 1);
	else
		return (counter_right + 1);
}
