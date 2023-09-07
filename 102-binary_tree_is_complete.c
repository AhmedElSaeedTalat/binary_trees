#include "binary_trees.h"
/**
 * find_height - find height of the tree
 *
 * @tree: pointer to the root node of the tree to check
 *
 * Return: the height of the tree
 */
int find_height(binary_tree_t *tree)
{
	int right, left;

	if (tree == NULL)
		return (0);
	left = find_height(tree->left);
	right = find_height(tree->right);
	if (left > right)
		return (left + 1);
	else
		return (right + 1);
}
/**
 * check_nodes - checks node of each level
 *
 * @tree: pointer to the root node of the tree to check
 * @level: level passed of tree
 *
 * Return: 0 if not complete one if complete
 */
int check_nodes(binary_tree_t *tree, int level)
{
	int left = 0, right = 0;
	static int count;

	if (tree == NULL)
		return (0);

	else if (tree->right && tree->left == NULL)
	{
		return (-1);
	}
	else if (level == 1)
	{
		if (tree->left && tree->right == NULL)
		{
			count += 1;
			return (2);
		}
		else if ((tree->left != NULL && count > 0) ||
				(tree->right != NULL && count > 0))
		{
			return (-1);
		}
	} else
	{
		left = check_nodes(tree->left, level - 1);
		right = check_nodes(tree->right, level - 1);
		if (left == -1 || right == -1 || count > 1)
		{
			return (0);
		} else
			return (1);
	}
	return (1);
}

/**
 * binary_tree_is_complete - checks if a binary tree is complete
 *
 * @tree: pointer to the root node of the tree to check
 *
 * Return: 0 if not complete one if complete
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
	int i, level, result, height = 0;

	if (tree == NULL)
		return (0);
	height = find_height((binary_tree_t *) tree);
	for (i = 1, level = 1; i < height; i++, level++)
		result = check_nodes((binary_tree_t *) tree, level);
	if (result == 0)
		return (0);
	else
		return (1);
}
