#include "shell.h"

/**
*shell_help - function that displays help information
*/

void shell_help(void)
{
_puts("\nShell Version 1.0.0\n\n");
_puts("usage: ./hsh\n\n");
_puts("Shell built-in commands:\n\n");
_puts("help\t\tDisplay this help information\n\n");
_puts("cd [dir]\tChange the current working directory\n\n");
_puts("env\t\tDisplay the enviroment variable\n\n");
_puts("setenv\t\tSet an enviroment variable\n\n");
_puts("unsetenv\tUnset an enviroment variable\n\n");
_puts("exit\t\tExit the shell\n\n");
}
