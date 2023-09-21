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
	char *str = NULL, **arr = NULL, *re = NULL;
	static int ex;

	while (ac < 2)
	{
		promp();

		str = command_line(ex);

		if (no_line(str) == 1)
		{
			free(str);
			continue;
		}

		arr = separate(str);

		re = path(arr);

		if (check(arr, env, ex) == 1)
		{
			continue;
		}

		ex = execute(arr, av[0], env, re);
	}
	return (0);
}
