#include <stdlib.h>
#include "binary_trees.h"

/**
 * binary_tree_node - Write a function that creates a binary tree node
 * @parent:  pointer
 * @value: new node
 * Return: new node, or NULL
 */

binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
	binary_tree_t *newNode;

	newNode = malloc(sizeof(binary_tree_t));

	if (newNode == NULL)
		return (NULL);

	newNode->n = value;
	newNode->left = NULL;
	newNode->right = NULL;

	if (parent == NULL)
	{
		parent = newNode;
		newNode->parent = NULL;
		return (newNode);
	}

	if (parent->left == NULL)
	{
		newNode->parent = parent;
		parent->left = newNode;
		return (newNode);
	}

	newNode->parent = parent;
	parent->right = newNode;
	return (newNode);
}
