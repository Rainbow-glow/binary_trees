#include "binary_trees.h"

/**
 * binary_tree_rotate_left - Left-rotates a binary tree.
 * @tree: A pointer to the root node of the tree to rotate.
 *
 * Return: A pointer to the new root node after rotation.
 */
binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree)
{
	binary_tree_t *fulcrum, *temp;

	if (tree == NULL || tree->right == NULL)
		return (NULL);

	fulcrum = tree->right;
	temp = fulcrum->left;
	fulcrum->left = tree;
	tree->right = temp;
	if (temp != NULL)
		temp->parent = tree;
	temp = tree->parent;
	tree->parent = fulcrum;
	fulcrum->parent = temp;
	if (temp != NULL)
	{
		if (temp->left == tree)
			temp->left = fulcrum;
		else
			temp->right = fulcrum;
	}

	return (fulcrum);
}
