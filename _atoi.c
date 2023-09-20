#include "shell.h"

/**
 * _atoi - Converts a string to an integer.
 * @s: The string to be converted.
 *
 * Return: The converted integer,
 * or -1 on error or if no numbers are in the string.
 */
int _atoi(char *s)
{
	int sign = 1;
	int result = 0;

	if (*s == '-')
	{
		sign = -1;
		s++;
	}
	while (*s)
	{
		if (*s >= '0' && *s <= '9')
		{
			result = result * 10 + (*s - '0');
			s++;
		}
		else
		{
			return (-1);
		}
	}
	return (sign * result);
}
