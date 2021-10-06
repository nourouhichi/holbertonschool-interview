#include "menger.h"
/**
* menger - print 2d menger sponge
* @level: level of the sponge
* Return: nothing
**/
void menger(int level)
{
int size = pow(3, level);
int i, j, x, m;
char c;
for (i = 0; i < size; i++)
{
for (j = 0; j < size; j++)
{
c = '#';
x = i;
for (m = j; m; m /= 3)
{
if (x % 3 == 1 && m % 3 == 1)
c = ' ';
x = x / 3;
}
printf("%c", c);
}
printf("\n");
}
}
