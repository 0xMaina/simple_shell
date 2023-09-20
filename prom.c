#include "shell.h"

/**
 * promp - prompt "$" to the user
 */
void promp(void)
{
	if (isatty(STDIN_FILENO) == 1)
	{
		write(STDOUT_FILENO, "$ ", 2);
	}
}
