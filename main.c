#include "shell.h"

/**
 * main - Entry point of the simple shell program.
 *
 * @ac: The number of command-line arguments.
 * @av: An array of strings representing the command-line arguments.
 * @env: An array of strings representing the environment variable
 *
 * Return: Always returns 0.
 */
int main(int ac, char **av, char **env)
{
	char *str = NULL, **arr = NULL;

	while (ac < 2)
	{
		promp();

		str = command_line();

		if (no_line(str) == 1)
		{
			free(str);
			continue;
		}

		arr = separate(str);

		if (check(arr, env) == 1)
		{
			continue;
		}

		execute(arr, av[0], env);
	}
	return (0);
}
