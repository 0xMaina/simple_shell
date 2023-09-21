#include "shell.h"

/**
 * execute - Execute a command with arguments.
 *
 * @str: An array of strings representing the command and its arguments.
 * @av: The name of the program (used for error messages).
 * @en: The array of environment variables.
 * @d: path
 *
 * Return: Returns 1 upon successful execution or -1 on failure.
 */
int execute(char **str, char *av, char **en, char *d)
{
	pid_t piid;
	int statu, ex = 0;
	static int num = 1;
	char opposite[100];

	if (access(d, X_OK) == 0)
	{
		piid = fork();
		if (piid == -1)
		{
			free_s(str);
			perror("fork");
			exit(1);
		}
		else if (piid == 0)
		{
			if (execve(d, str, en) == -1)
			{
				free_s(str);
				perror("malloc");
				exit(127);
			}
		}
		else
		{
			waitpid(piid, &statu, WUNTRACED);
		}
	}
	else if (access(d, X_OK) != 0)
	{
		convert_num_to_string(num, opposite);
		_print_error(av, str[0], opposite);
		ex = 127;
		num++;
	}
	free_s(str);
	return (ex);
}

/**
 * _print_error - print error message
 *
 * @av: first argument
 * @str: first string
 * @opposite: an char
 */
void _print_error(char *av, char *str, char *opposite)
{
	write(2, av, len_str(av));
	write(2, ": ", len_str(": "));
	write(2, opposite, len_str(opposite));
	write(2, ": ", len_str(": "));
	write(2, str, len_str(str));
	write(2, ": not found\n", len_str(": not found\n"));
}

/**
 * convert_num_to_string - convert number to string
 *
 * @num: number
 * @opposite: converted number
 */
void convert_num_to_string(int num, char *opposite)
{
	size_t index = 0;
	int store = 0;

	store = num;

	while (store > 0)
	{
		store /= 10;
		index++;
	}

	opposite[index] = '\0';

	while (index > 0)
	{
		opposite[--index] = '0' + (num % 10);
		num /= 10;
	}
}
