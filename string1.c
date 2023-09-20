#include "shell.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define WRITE_BUF_SIZE 1024
#define BUF_FLUSH '\0'

/**
 * _strcpy - Copy one string to another.
 * @dest: The destination string.
 * @src: The source string.
 *
 * Return: A pointer to the destination string.
 */
char *_strcpy(char *dest, const char *src)
{
	int i = 0;

	/* Check if destination is same as source or if the source is NULL. */
	if (dest == src || src == NULL)
		return (dest);

	/* Copy the characters from the source to the destination. */
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

/**
 * _strdup - Duplicate a string.
 * @str: The string to be duplicated.
 *
 * Return: A pointer to the duplicated string.
 */
char *_strdup(const char *str)
{
	int length = 0;
	char *ret;

	/* Check if the input string is NULL. */
	if (str == NULL)
		return (NULL);

	/* Calculate the length of the input string. */
	while (str[length])
		length++;

	/* Allocate memory for the duplicated string. */
	ret = malloc(sizeof(char) * (length + 1));

	/* Check if memory allocation was successful. */
	if (!ret)
		return (NULL);

	/* Copy characters from the input string to the duplicated string. */
	for (int i = 0; i <= length; i++)
		ret[i] = str[i];

	return (ret);
}

/**
 * _puts - Print a string to standard output.
 * @str: The string to be printed.
 *
 * No Return value
 */
void _puts(const char *str)
{
	/* Check if the input string is NULL. */
	if (str == NULL)
		return;

	/* Print each character of the input string to standard output. */
	for (int i = 0; str[i] != '\0'; i++)
		_putchar(str[i]);
}

/**
 * _putchar - Write a character to standard output.
 * @c: The character to be printed.
 *
 * Return: 1 on success, -1 on error (with errno set appropriately).
 */
int _putchar(char c)
{
	static int i;
	static char buf[WRITE_BUF_SIZE];

	/* Check if it's time to flush the buffer or if the buffer is full. */
	if (c == BUF_FLUSH || i >= WRITE_BUF_SIZE)
	{
		write(1, buf, i);
		i = 0;
	}

	/* Store the character in the buffer unless it's a flush character. */
	if (c != BUF_FLUSH)
		buf[i++] = c;

	return (1);
}
