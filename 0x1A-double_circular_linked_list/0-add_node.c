#include <stdio.h>
#include <stdlib.h>
#include "list.h"
/**
 * create - Creates a node with the given data
 * @str: the string to copy into the new node
 * Return: pointer to the newly created node
 */
List *create(char *str)
{
List *node = NULL;
node = malloc(sizeof(List));
if (node)
node->str = str;
return (node);
}
/**
 * add_node_end - Adds a new node to the end of a double circular linked list
 * @list: the list to modify
 * @str: the string to copy into the new node
 * Return: a pointer to the newly added node
 */
List *add_node_end(List **list, char *str)
{
List *new_end, *tail;
new_end = create(str);
if (!new_end)
return (NULL);
if (!*list)
{
*list = new_end;
new_end->next = new_end;
new_end->prev = new_end;
return (new_end);
}
tail = (*list)->prev;
tail->next = new_end;
(*list)->prev = new_end;
new_end->prev = tail;
new_end->next = *list;
return (new_end);
}
/**
 * add_node_begin - Adds a new node to the beginning of a double circular
 * linked list
 * @list: the list to modify
 * @str: the string to copy into the new node
 * Return: a pointer to the newly added node
 */
List *add_node_begin(List **list, char *str)
{
List *new_start, *tail;
new_start = create(str);
if (!new_start)
return (NULL);
if (!*list)
{
*list = new_start;
new_start->next = new_start;
new_start->prev = new_start;
return (new_start);
}
tail = (*list)->prev;
tail->next = new_start;
(*list)->prev = new_start;

new_start->prev = tail;
new_start->next = *list;
*list = new_start;
return (new_start);
}
