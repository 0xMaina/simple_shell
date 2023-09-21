#include "shell.h"

/**
 * command_line - Read a line of input from the user.
 *
 * @ex: exit number
 *
 * Return: A dynamically allocated string containing the user's input.
 *
 * This string should be freed when no longer needed.
 */
char *command_line(int ex)
{
	char *li = NULL;
	size_t buf = 0;
	ssize_t re;

	signal(SIGINT, SIG_IGN);

	re = getline(&li, &buf, stdin);

	if (re == -1)
	{
		free(li);
		if (isatty(STDIN_FILENO) != 0)
		{
			write(STDOUT_FILENO, "\n", 1);
		}
		if (ex == -1)
			ex = 0;
		exit(ex);
	}

	return (li);
}
