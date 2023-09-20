#include "shell.h"

/**
 * len_str - count the lenght of a string
 *
 * @string: string to count
 *
 * Return: number of char
 */
size_t len_str(const char *string)
{
	size_t len = 0;

	while (string[len])
	{
		len++;
	}

	return (len);
}
