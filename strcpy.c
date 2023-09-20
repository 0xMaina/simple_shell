#include "shell.h"

/**
 * str_cpy - copie the content of string to srcc
 *
 * @string: destination argument
 * @srcc: source
 *
 * Return: copy of the string
 */
char *str_cpy(char *string, const char *srcc)
{
	char *tm = string;

	while (*srcc)
	{
		*string++ = *srcc++;
	}
	*string = '\0';

	return (tm);
}
