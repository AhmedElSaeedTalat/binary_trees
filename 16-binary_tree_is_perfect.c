#include "binary_trees.h"
/**
 * measure_height - measure height
 *
 * @tree: pointer to the root node of the tree
 *
 * Return: heught
 */
int measure_height(const binary_tree_t *tree)
{
	int left, right;

	if (tree == NULL)
		return (0);
	left = measure_height(tree->left);
	right = measure_height(tree->right);
	if (left > right)
		return (left + 1);
	else
		return (right + 1);
}
/**
 * check_nodes - checks if node has 2 children and if leaves in right level
 *
 * @tree: pointer to the root node of the tree
 * @height: height of the tree
 * @level: level of tree
 *
 * Return: 1 in case true
 */
int check_nodes(const binary_tree_t *tree, int height, int level)
{
	if (tree == NULL)
		return (0);
	if ((tree->left != NULL && tree->right == NULL) ||
			(tree->right != NULL && tree->left == NULL))
	{
		return (0);
	}
	if (tree->left == NULL && tree->right == NULL)
	{
		if (level != height)
		{
			return (0);
		}
	}
	if (tree->left && tree->right)
		return (check_nodes(tree->left, height, level + 1) &&
				check_nodes(tree->right, height, level + 1));
	else
		return (1);
}
/**
 * binary_tree_is_perfect - checks if a binary tree is perfect
 *
 * @tree: pointer to the root node of the tree
 *
 * Return: 1 if tree is perfect
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	int height, height_left, height_right, checker, level = 1;

	if (tree == NULL)
		return (0);
	height_left = measure_height(tree->left);
	height_right = measure_height(tree->right);
	height = measure_height(tree);
	checker = check_nodes(tree, height, level);
	if (height_left == height_right && checker == 0)
		return (0);
	if (height_left != height_right)
		return (0);
	return (1);
}
