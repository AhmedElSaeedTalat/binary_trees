#include "binary_trees.h"
#include <limits.h>
/**
 * check_binary - checks if bst
 *
 * @tree: pointer to root of tree
 * @min_value: to compare current node with min value
 * @max_value: to compare current node with max value
 *
 * Return: 1 if bst and 0 if not
 */
int check_binary(binary_tree_t *tree, int min_value, int max_value)
{
	if (tree == NULL) /* base case */
		return (400);

	else if (tree->right)
	{
		if (tree->n >= tree->right->n)
		{
			return (0);
		}
	}
	else if (tree->left)
	{
		if (tree->n <= tree->left->n)
		{
			return (0);
		}
	} else if (tree->n > max_value || tree->n < min_value)
	{
		return (0);
	} else
		return (1);
	return (check_binary(tree->left, min_value, tree->n - 1)
			&& check_binary(tree->right, tree->n + 1, max_value));
}

/**
 * binary_tree_is_bst - check if bst
 *
 * @tree: pointer to root tree
 *
 * Return: 1 if it's bst and 0 if not
 */
int binary_tree_is_bst(const binary_tree_t *tree)
{
	int result = 0;

	if (tree == NULL)
		return (0);
	result = check_binary((binary_tree_t *) tree, INT_MIN, INT_MAX);
	return (result);
}
