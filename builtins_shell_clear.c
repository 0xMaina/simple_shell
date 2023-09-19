#include "shell.h"

/**
*shell_clear - function that clear terminal
*@args: arguments
*
*Return: 1 for continue else 0
*/

int shell_clear(char **args)
{
(void)args;
_puts("\033[2j\033[H");
return (1);
}
