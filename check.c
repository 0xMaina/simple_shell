#include "shell.h"

/**
 * check - check if string is env or exit and execute it
 *
 * @string: string
 * @env: environment
 *
 * Return: 1 if env match or 0 if not
 */
int check(char **string, char **env)
{
	unsigned int i = 0, len = 0;

	while (string[len] != NULL)
	{
		len++;
	}

	if ((len == 1) && (strcmp(string[0], "env") == 0))
	{
		while (env[i] != NULL)
		{
			write(STDOUT_FILENO, env[i], len_str(env[i]));
			write(STDOUT_FILENO, "\n", 1);
			i++;
		}
		for (i = 0; string[i]; i++)
		{
			free(string[i]);
		}
		free(string);
		return (1);
	}
	else if ((len == 1) && (strcmp(string[0], "exit") == 0))
	{
		for (i = 0; string[i]; i++)
		{
			free(string[i]);
		}
		free(string);
		exit(2);
	}
	return (0);
}
