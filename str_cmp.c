#include "shell.h"

/**
 * compare- compare between 's' and 'c'
 *
 * @s: string
 * @c: string
 *
 * Return: 0 if they have the same char
 * and -1 if not
 */
int compare(const char *s, const char *c)
{
	int i = 0;

	while (s[i] && c[i])
	{
		if (s[i] != c[i])
		{
			return (s[i] - c[i]);
		}
		i++;
	}

	return (0);
}
