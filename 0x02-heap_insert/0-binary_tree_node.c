#include <stdlib.h>
#include "binary_trees.h"

#include "binary_trees.h"

/**
 * binary_tree_node - Creates a new node
 * @parent: new node
 * @value: node value
 * Return: new node, or NULL on fail
 */

binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
	binary_tree_t *new_node = NULL;

	new_node = malloc(sizeof(*new_node));
	if (!new_node)
		return (NULL);

	new_node->parent = parent;
	new_node->n = value;
	new_node->left = NULL;
	new_node->right = NULL;

	return (new_node);
}
