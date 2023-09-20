#include "shell.h"

/**
*shell_env - function that prints env
*
*Return: void
*/

int shell_env(void)
{
int i;

for (i = 0; environ[1]; i++)
{
_puts(environ[i]);
_putchar('\n');
}
return (0);
}

