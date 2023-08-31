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
 * binary_tree_is_perfect - checks if a binary tree is perfect
 *
 * @tree: pointer to the root node of the tree
 *
 * Return: 1 if tree is perfect
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	int height_left, height_right;

	if (tree == NULL)
		return (0);
	height_left = measure_height(tree->left);
	height_right = measure_height(tree->right);
	if (height_left != height_right)
		return (0);
	return (1);
}
