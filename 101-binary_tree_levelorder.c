#include "binary_trees.h"
/**
 * find_height - finds height of tree
 *
 * @tree: root of tree
 *
 * Return: height
 */
int find_height(binary_tree_t *tree)
{
	int left = 0, right = 0;

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
 * print_node - print node
 *
 * @tree: root of tree
 * @level: level to print
 * @func: passed function
 */
void print_node(binary_tree_t *tree, int level, void (*func)(int))
{
	if (tree == NULL)
		return;
	if (level == 1)
		func(tree->n);
	if (level > 1)
	{
		print_node(tree->left, level - 1, func);
		print_node(tree->right, level - 1, func);
	}
}
/**
 * binary_tree_levelorder - goes through binary tree using lvl-order traversal
 *
 * @tree: root of tree
 * @func: passed function
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	int height = 0, level = 0, i = 0;

	if (tree == NULL || func == NULL)
		return;
	height = find_height((binary_tree_t *) tree);
	for (i = 1, level = 1; i <= height; i++, level++)
		print_node((binary_tree_t *) tree, level, func);

}
