#include "binary_trees.h"

/**
 * array_to_avl - Builds an AVL tree from an array.
 * @size: The number of elements in @array.
 * @array: A pointer to the first element of the array to be converted.
 *
 * Return: A pointer to the root node of the created AVL, or NULL upon failure.
 */
avl_t *array_to_avl(int *array, size_t size)
{
	size_t i, j;
	avl_t *tree = NULL;

	if (array == NULL)
		return (NULL);

	for (i = 0; i < size; i++)
	{
		for (j = 0; j < i; j++)
		{
			if (array[j] == array[i])
				break;
		}
		if (j == i)
		{
			if (avl_insert(&tree, array[i]) == NULL)
				return (NULL);
		}
	}

	return (tree);
}
