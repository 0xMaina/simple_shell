#include "shell.h"

/**
 * str_dup - duplicate content of str and return it
 *
 * @src: string to dup
 *
 * Return: duplicated string or NULL if fail
 */
char *str_dup(const char *src)
{
	size_t len = 0, i;
	char *s = NULL;

	if (src == NULL)
	{
		return (NULL);
	}

	len = len_str(src);

	s = malloc((len + 1) * sizeof(char));

	if (s == NULL)
	{
		return (NULL);
	}
	for (i = 0; i < len; i++)
	{
		s[i] = src[i];
	}

	s[len] = '\0';

	return (s);
}
