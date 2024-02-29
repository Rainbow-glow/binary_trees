#include "binary_trees.h"

/**
 * bal - Measures balance factor of a AVL
 * @tree: tree to go through
 * Return: balanced factor
 */
void bal(avl_t **tree)
{
	int bval;

	if (tree == NULL || *tree == NULL)
		return;
	if ((*tree)->left == NULL && (*tree)->right == NULL)
		return;
	bal(&(*tree)->left);
	bal(&(*tree)->right);
	bval = binary_tree_balance((const binary_tree_t *)*tree);
	if (bval > 1)
		*tree = binary_tree_rotate_right((binary_tree_t *)*tree);
	else if (bval < -1)
		*tree = binary_tree_rotate_left((binary_tree_t *)*tree);
}
/**
 * successor - get the next successor i mean the min node in the right subtree
 * @node: tree to check
 * Return: the min value of this tree
 */
int successor(bst_t *node)
{
	int left = 0;

	if (node == NULL)
	{
		return (0);
	}
	else
	{
		left = successor(node->left);
		if (left == 0)
		{
			return (node->n);
		}
		return (left);
	}

}
/**
 *remove_type - function that removes a node depending of its children
 *@base_root: node to remove
 *Return: 0 if it has no children or other value if it has
 */
int remove_type(bst_t *base_root)
{
	int new_value = 0;

	if (!base_root->left && !base_root->right)
	{
		if (base_root->parent->right == base_root)
			base_root->parent->right = NULL;
		else
			base_root->parent->left = NULL;
		free(base_root);
		return (0);
	}
	else if ((!base_root->left && base_root->right) || (!base_root->right && base_root->left))
	{
		if (!base_root->left)
		{
			if (base_root->parent->right == base_root)
				base_root->parent->right = base_root->right;
			else
				base_root->parent->left = base_root->right;
			base_root->right->parent = base_root->parent;
		}
		if (!base_root->right)
		{
			if (base_root->parent->right == base_root)
				base_root->parent->right = base_root->left;
			else
				base_root->parent->left = base_root->left;
			base_root->left->parent = base_root->parent;
		}
		free(base_root);
		return (0);
	}
	else
	{
		new_value = successor(base_root->right);
		base_root->n = new_value;
		return (new_value);
	}
}
/**
 * bst_remove - remove a node from a BST tree
 * @base_root: base_root of the tree
 * @value: node with this value to remove
 * Return: the tree changed
 */
bst_t *bst_remove(bst_t *base_root, int value)
{
	int type = 0;

	if (base_root == NULL)
		return (NULL);
	if (value < base_root->n)
		bst_remove(base_root->left, value);
	else if (value > base_root->n)
		bst_remove(base_root->right, value);
	else if (value == base_root->n)
	{
		type = remove_type(base_root);
		if (type != 0)
			bst_remove(base_root->right, type);
	}
	else
		return (NULL);
	return (base_root);
}

/**
 * avl_remove - remove a node from a AVL tree
 * @base_root: base_root of the tree
 * @value: node with this value to remove
 * Return: the tree changed
 */
avl_t *avl_remove(avl_t *base_root, int value)
{
	avl_t *base_root_a = (avl_t *) bst_remove((bst_t *) base_root, value);

	if (base_root_a == NULL)
		return (NULL);
	bal(&base_root_a);
	return (base_root_a);
}
