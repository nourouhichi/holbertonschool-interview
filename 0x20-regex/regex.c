#include "regex.h"

/**
 * regex_match - compares two strings
 * @str: string
 * @pattern: string
 * Return: 1 or 0
 */
int regex_match(char const *str, char const *pattern)
{
	int tmp = 0;

	if (*str == '\0' && *pattern == '\0')
		return (1);
	if ((*str == *pattern || *pattern == '.') && *(pattern + 1) != '*')
		return (regex_match(str + 1, pattern + 1));
	if (*(pattern + 1) == '*')
	{

		return (regex_match(str, pattern + 2) || tmp);
	}
	return (0);
}
