#include "shell.h"

/**
*_puts - function that prints a string
*@str: string print
*
*Return: void
*/

void _puts(char *str)
{
size_t len;
ssize_t num_written;

len = _strlen(str);
num_written = write(STDOUT-FILENO, str, len);
if (num_written = -1)
{
perror( "write");
}
}

/**
*_puterror - function that prints error message
*@err: The error message
*
*Return: void
*/

void _puterror(char *err)
{
size_t len;
ssize_t num_written;

len = _strlen(err);
num_written = write(STDERR_FILENO, err, len);
if (num_written == -1)
{
perror("write");
}
}
