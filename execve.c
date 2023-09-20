#include "shell.h"

/**
 * execute - Execute a command with arguments.
 *
 * @str: An array of strings representing the command and its arguments.
 * @av: The name of the program (used for error messages).
 * @en: The array of environment variables.
 *
 * Return: Returns 1 upon successful execution or -1 on failure.
 */
int execute(char **str, char *av, char **en)
{
	pid_t piid;
	int statu;

	if (access(str[0], X_OK) == 0)
	{
		piid = fork();

		if (piid == -1)
		{
			free_s(str);
			perror(av);
			exit(1);
		}
		else if (piid == 0)
		{
			if (execve(str[0], str, en) == -1)
			{
				free_s(str);
				perror(str[0]);
				exit(127);
			}
		}
		else
		{
			waitpid(piid, &statu, WUNTRACED);
		}
	}
	else
	{
		perror(av);
	}
	free_s(str);

	return (0);
}
