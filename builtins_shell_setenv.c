#include "shell.h"

/**
*shell_setenv - function that sets value of env
*@args: argument
*
*Return: nothing
*/

int shell_setenv(char **args)
{
char *name, *value;
if (args[1] == NULL || args[2] == NULL)
{
_puterror("usage: setenv VARIABLE VALUE\n");
return (-1);
}

name = args[1];
value = args[2];

if (setenv(name, value, 1) != 0)
{
_puterror("setenv");
return (-1);
}
return (0);
}

/**
*shell_unsetenv - function that unsets env
*@args: Arguments
*
*Return: nothing
*/

int shell_unsetenv(char **args)
{
char *name;

if (args[1] == NULL)
{
_puterror("Usage: unsetenv VARIABLE\n");
return (-1);
}

name = args[1];

if (unsetenv(name) != 0)
{
_puterror("unsetenv");
}
return (0);
}
