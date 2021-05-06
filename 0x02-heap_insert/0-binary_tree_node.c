#include <stdio.h>
#include <stdlib.h>
#include "binary_trees.h"

/**
 * binary_tree_node - inserts a node in a sorted one
 * @parent: the parent
 * @value: data in the node
 * Return: an address to the inserted node
 */

binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
binary_tree_t *new_child = malloc(sizeof(binary_tree_t));
if (!new_child)
return (NULL);
new_child->parent = parent;
new_child->left = new_child->right = NULL;
new_child->n = value;
return (new_child);
}
