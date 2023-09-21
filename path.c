#include "shell.h"

/**
 * append - add src to dest
 *
 * @dest: destination
 * @src: source
 *
 * Return: destination
 */
char *append(char *dest, char *src)
{
	int len = 0, i;

	while (dest[len])
	{
		len++;
	}

	for (i = 0; src[i]; i++, len++)
	{
		dest[len] = src[i];
	}

	dest[len] = '\0';

	return (dest);
}

/**
 * added - append tok and arg[0] to arr
 *
 * @arr: store string
 * @arg: argument
 * @tok: tokenize
 *
 * Return: arr
 */
char *added(char *arr, char **arg, char *tok)
{
	int length = 0, i;

	for (i = 0; i < 100; i++)
	{
		arr[i] = 0;
	}

	length = strlen(tok) + strlen(arg[0]) + 2;

	append(arr, tok);
	append(arr, "/");
	append(arr, arg[0]);

	arr[length - 1] = '\0';

	return (arr);
}

/**
 * str_check - check for '/' in first char
 *
 * @str: string
 * @d: deli
 *
 * Return: 0 or 1
 */
int str_check(char *str, char d)
{
	if (str[0] == d)
	{
		return (1);
	}
	else
		return (0);
}

/**
 * path - handle path
 *
 * @str: string
 *
 * Return: path
 */
char *path(char **str)
{
	char *PATH = NULL, *tok = NULL, *cpy = NULL;
	char *path = NULL, *q = NULL;
	static char arr[100];
	int passed = 0;

	struct stat S;

	PATH = getenv("PATH");
	q = str_dup(PATH);
	tok = strtok(q, ": =");

	while (tok)
	{
		cpy = added(arr, str, tok);

		if (stat(cpy, &S) == 0)
		{
			path = cpy;
			passed = 1;
			break;
		}

		tok = strtok(NULL, ":'\0'");
	}

	if (passed == 0)
	{
		path = str[0];
	}

	free(q);

	return (path);
}
