#include "shell.h"
/**
 * @str: the string to be printed
 * _eputs: prints an input string to stderr
 * Return: Nothing
 */
void _eputs(char *str)
{
	int i = 0;

	if (!str)
	return;
	while (str[i] != '\0')
	{
		_eputchar(str[i]);
		i++;
	}
}
/**
 * @c: The character to print
 * _eputchar: writes the character c to stderr
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _eputchar(char c)
{
	static int i;
	static char buf[WRITE_BUF_SIZE];

	if (c == BUF_FLUSH || i >= WRITE_BUF_SIZE)
	{
		write(2, buf, i);
		i = 0;
	}
	if (c != BUF_FLUSH)
	buf[i++] = c;
	return (1);
}
/**
 * _putfd - writes the char c to the given file descriptor
 * @c: character to print
 * @fd: fd to write to
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putfd(char c, int fd)
{
	static int i;
	static char buf[WRITE_BUF_SIZE];

	if (c == BUF_FLUSH || i >= WRITE_BUF_SIZE)
	{
		write(fd, buf, i);
		i = 0;
	}
	if (c != BUF_FLUSH)
		buf[i++] = c;
	return (1);
}
/**
 * _putsfd - prints an input string to the given file descriptor
 * @str: string to be printed
 * @fd: fd to write to
 *
 * Return: the number of characters written
 */
int _putsfd(char *str, int fd)
{
	int i = 0;
	
	if (!str)
	return (0);
	while (*str)
	{
		i += _putfd(*str++, fd);
	}
	return (i);
}
