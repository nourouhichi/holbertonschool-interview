#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

/**
 * is_palindrome - checks if a singly linked list is a palindrome
 * @head: pointer to head of list
 * Return: 1 if success 0 if not
 */
int is_palindrome(listint_t **head)
{
listint_t *roadrunner = (*head);
int i = 1, y, x, z = 0;
int *array;

if (!(*head) || !head)
return (1);
while (roadrunner->next)
{
i++;
roadrunner = roadrunner->next;
}
if (i % 2 != 0)
return (0);
array = malloc(sizeof(int) * i);
if (!array)
return (0);
roadrunner = (*head);
x = 0;
while (x < i)
{
array[x] = roadrunner->n;
x++;
roadrunner = roadrunner->next;
}
for (z = i / 2 - 1, y = i / 2 ; z != -1; z--, y++)
{
if (array[z] != array[y])
{
free(array);
return (0);
}
}
free(array);
return (1);
}