#include "lists.h"

/**
 * check_cycle - checks wether a list has a cycle
 * @list: pointer to head of list
 * Return: o or 1
 */
int check_cycle(listint_t *list)
{
listint_t *p1 = list, *p2 = list;

if (!list)
return (0);
while (p2 && p2->next)
{
p1 = p1->next;
p2 = p2->next->next;
if (p1 == p2)
return (1);
}
return (0);
}
