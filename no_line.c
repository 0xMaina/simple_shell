#include "shell.h"

/**
 * no_line - check if s it is an empty string
 *
 * @s: string
 *
 * Return: 1 in fails or 0 in success
 */
int no_line(char *s)
{
	int i = 0;

	while (s[i] != '\n')
	{
		if (s[i] != ' ')
		{
			return (0);
		}

		i++;
	}

	return (1);
}
