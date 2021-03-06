#include "binary_trees.h"

/**
 * height - recursively counts the height of a heap
 * @root: the first node of the heap
 * Return: returns the height of the heap
 */
int height(heap_t *root)
{
size_t left, right;

	if (!root)
		return (0);
	if (!root->left && !root->right)
		return (0);

	right = height(root->right) + 1;
	left = height(root->left) + 1;

	if (left > right)
		return (left);
	else
		return (right);
}

/**
 * rebuild_heap - rebuilding a heap
 * @node: root of the heap
 */
void rebuild_heap(heap_t *node)
{
	int value;
	heap_t *tmp1, *tmp2;

	if (!node)
		return;
	tmp1 = node;
	while (1)
	{
		if (!tmp1->left)
			break;
		if (!tmp1->right)
			tmp2 = tmp1->left;
		else
		{
			if (tmp1->left->n > tmp1->right->n)
				tmp2 = tmp1->left;
			else
				tmp2 = tmp1->right;
		}
		if (tmp1->n > tmp2->n)
			break;
		value = tmp1->n;
		tmp1->n = tmp2->n;
		tmp2->n = value;
		tmp1 = tmp2;
	}
}

/**
 * pre_order - using pre-order traversal
 * @tree: pointer to the root node
 * @root: will be last note in traverse
 * @height: the height of the array to fill
 */
void pre_order(heap_t *tree, heap_t **root, int height)
{

if (!tree)
	return;

if (!height)
	*root = tree;

	height--;
	pre_order(tree->left, root, height);
	pre_order(tree->right, root, height);
}
/**
 * heap_extract - extracts the root node
 * @root:pointer to the parent node
 * Return: the value stored in the root node
 */

int heap_extract(heap_t **root)
{
	int n, size;
	heap_t *tree, *heap;

	if (!root || !*root)
		return (0);
	n = (*root)->n;
	size = height(*root);
	tree = *root;

	if (!tree->left && !tree->right)
	{
		*root = NULL;
		free(tree);
		return (n);
	}
	pre_order(tree, &heap, size);
	tree->n = heap->n;
	if (heap->parent->right)
		heap->parent->right = NULL;
	else
		heap->parent->left = NULL;
	free(heap);
	rebuild_heap(tree);
	return (n);
}
