#include "binary_trees.h"
/**
 * height - calculate the height of a binary tree
 *
 * @tree: pointer to the root node of the tree
 *
 * Return: the height
 */
int height(const binary_tree_t *tree)
{
	int left = 0, right = 0;

	if (tree == NULL)
		return (0);

	left = height(tree->left);
	right = height(tree->right);
	if (left > right)
		return (left + 1);
	else
		return (right + 1);
}


/**
 * binary_tree_balance - measures the balance factor of a binary tree
 *
 * @tree: pointer to the root node of the tree
 *
 * Return: the balance factor
 */
int binary_tree_balance(const binary_tree_t *tree)
{
	int left_height = 0, right_height = 0;

	if (tree == NULL)
		return (0);

	left_height = height(tree->left);
	right_height = height(tree->right);
	return (left_height - right_height);
}
