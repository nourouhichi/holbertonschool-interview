#include "palindrome.h"

/**
 * is_palindrome - Entry point
 * @n: integer to check
 * Return: 0 or 1
 */
int is_palindrome(unsigned long n)
{
int reverse = 0;
int tmp = n;
int r;
while (n != 0)
{
r = n % 10;
reverse = reverse * 10 + r;
n /= 10;
}
if (tmp == reverse)
return (1);
return (0);
}
