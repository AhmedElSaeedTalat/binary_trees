#include "binary_trees.h"
/**
 * check_binary - checks if bst
 *
 * @tree: pointer to root of tree
 *
 * Return: 1 if bst and 0 if not
 */
int check_binary(binary_tree_t *tree)
{
	if (tree == NULL) /* base case */
		return (500);

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
	}
	else
		return (1);
	return (check_binary(tree->left) && check_binary(tree->right));
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
	result = check_binary((binary_tree_t *) tree);
	return (result);
}
