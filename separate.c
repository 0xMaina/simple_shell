#include "shell.h"

/**
 * free_str - free array of string from separate
 * function
 *
 * @string: original str
 * @arr: array
 * @i: number that specify when malloc fail
 *
 */
void free_str(char *string, char **arr, int i)
{
	int j;

	for (j = 0; j < i; j++)
	{
		free(arr[j]);
	}
	free(arr);
	free(string);
	perror("malloc");
	exit(1);
}

/**
 * split - split string
 *
 * @s: string
 *
 * Return: number of string
 */
int split(char *s)
{
	int i, src = 1, cm = 0;

	for (i = 0; s[i]; i++)
	{
		if (s[i] != ' ' && src == 1)
		{
			cm += 1;
			src = 0;
		}
		if (s[i + 1] == ' ')
		{
			src = 1;
		}
	}
	return (cm);
}

/**
 * separate - Split a string into an array of substrings.
 *
 * @string: The string to be split.
 *
 * Return: An array of substrings.
 */
char **separate(char *string)
{
	char **arr = NULL, *mv = NULL;
	int i = 0, number = 0;

	number = split(string);
	arr = malloc(sizeof(char *) * (number + 1));

	if (arr == NULL)
	{
		free(string);
		perror("malloc");
		exit(1);
	}

	mv = strtok(string, " \t\n");

	while (mv != NULL)
	{
		arr[i] = str_dup(mv);
		if (arr[i] == NULL)
		{
			free_str(string, arr, i);
		}
		mv = strtok(NULL, " \t\n");
		i++;
	}
	arr[i] = NULL;
	free(string);
	return (arr);
}
