#include "shell.h"

/**
 * free_s - free a string of array
 *
 * @string: array
 */
void free_s(char **string)
{
	int i;

	for (i = 0; string[i]; i++)
	{
		free(string[i]);
	}

	free(string);
}
