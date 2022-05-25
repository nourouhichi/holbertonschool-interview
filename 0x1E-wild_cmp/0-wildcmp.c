#include "holberton.h"

/**
 * wildcmp - compares two strings
 * @s1: string 1
 * @s2: string 2
 * Return: 1 or 0
 */
int wildcmp(char *s1, char *s2)
{
if (!*s1)
{
if (*s2 == '*')
return (wildcmp(s1, s2 + 1));
return (!*s2);
}
if (*s2 == '*')
return (wildcmp(s1 + 1, s2) || wildcmp(s1, s2 + 1));
if (*s1 == *s2)
return (wildcmp(s1 + 1, s2 + 1));
return (0);
}
