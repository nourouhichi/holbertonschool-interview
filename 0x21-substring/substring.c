#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "substring.h"


/**
 * find_substring - Entry point
 * @s: char const
 * @words: char const
 * @nb_words: int
 * @n: int
 * Return: 0, 1
*/
int *find_substring(char const *s, char const **words, int nb_words, int *n)
{
int x = 0, y, c, *res, *picked, len, wlen;

res = (int *)malloc(len * sizeof(int));
picked = (int *)malloc(nb_words * sizeof(int));
if (!res && !picked)
return (NULL);
len = strlen(s);
wlen = strlen(words[0]);
while (x <= len - nb_words * wlen)
{
for (y = 0; y < nb_words; y++)
{
picked[y] = 0;
}
for (y = 0; y < nb_words; y++)
{
for (c = 0; c < nb_words; c++)
{
if (picked[c] == 0 && strncmp(s + x + y * wlen, words[c], wlen) == 0)
{
picked[c] = 1;
break;
}
}
if (c == nb_words)
{
break;
}
}
if (y == nb_words)
{
res[(*n)++] = x + 1;
}
x++;
}
free(picked);
return (res);
}
