#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "binary_trees.h"

/**
 * binary_tree_node - inserts a node in a sorted one
 * @parent: the parent
 * @value: data in the node
 * Return: an address to the inserted node
 */
heap_t *heap_insert(heap_t **root, int value)
{
	heap_t *new_child = malloc(sizeof(binary_tree_t)), *new;
	int y =  binary_tree_depth(*root);
	if (!new_child)
		return (NULL);
	new_child->left = new_child->right = NULL;
	new_child->n = value;
	if (*root == NULL)
	{
		*root = new_child;
		return (new_child);
	}
	else
		new = insert(root, value, y);
	return (new);

}
heap_t *insert(heap_t **node, int value, int y)
{
	heap_t *road_runner; 
	binary_tree_t *new;
	road_runner = *node;
	int n, x;
	int p = pow(2, y);

	if (road_runner->left && road_runner->right)
	{
		n = binary_tree_size(road_runner->left);
		x = binary_tree_size(road_runner->right);
		if ((n - p == x || n - p == x - 1) && (y > 0) && (n - p != 0))
			road_runner = road_runner->right;
		else
			road_runner = road_runner->left;
	}
	
	while (road_runner->left != NULL)
	{
		if (road_runner->right == NULL)
		{
			new = binary_tree_node(road_runner, value);
			road_runner->right = new;
			return (new);
		}
		else
			road_runner = road_runner->left;
	}
	new = binary_tree_node(road_runner, value);
	road_runner->left = new;
	
	return new;
}

int binary_tree_size(heap_t *tree)
{
	int n, m;

	if (tree == NULL)
		return (0);
	m = binary_tree_size(tree->left);
	n = binary_tree_size(tree->right);
	return (n + m + 1);
}

int binary_tree_depth(heap_t *tree)
{
int n = 0;
heap_t *runner = tree;

if ((tree) == NULL)
return (0);
while (runner->left)
{
	n++;
	runner = runner->left;
}
return (n - 1);
}