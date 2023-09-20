#include "shell.h"

/**
 * _exitt - exits the shell
 * @argv: Array of command arguments (argv[0] is the command itself)
 * Return: exits with a given exit status
 */
int _exitt(char **argv)
{
	int exit_status = 0;

	if (argv[1])
	{
		int exitcheck = _atoi(argv[1]);

		if (exitcheck == -1)
		{
			write(1, "exit\n", strlen("exit\n"));
			write(1, argv[1], strlen(argv[1]));
			write(1, ": numeric argument required\n",
				strlen(": numeric argument required\n"));
			exit(2);
		}
		else
			exit_status = exitcheck;
	}
	write(1, "exit\n", strlen("exit\n"));
	exit(exit_status);
	return (0);
}
