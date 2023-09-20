#include <stdio.h>
#include <string.h>

/**
 * _strlen - Calculate the length of a string.
 * @s: The input string for which the length is determined.
 *
 * Return: The number of characters in the string.
 */
size_t _strlen(const char *s)
{
	if (!s)
		return (0);

	return (strlen(s));
}

/**
 * _strcmp - Compare two strings lexicographically.
 * @s1: The first string to compare.
 * @s2: The second string to compare.
 *
 * Return: A negative value if s1 comes before s2, positive otherwise
 * or zero if s1 and s2 are equal.
 */
int _strcmp(const char *s1, const char *s2)
{
	return (strcmp(s1, s2));
}

/**
 * starts_with - Check if a string begins with another string.
 * @haystack: The string in which we are searching.
 * @needle: The substring we are looking for at the beginning of haystack.
 *
 * Return: A pointer to the character if no match is found.
 */
const char *starts_with(const char *haystack, const char *needle)
{
	if (strncmp(haystack, needle, strlen(needle)) == 0)
		return (haystack + strlen(needle));
	return (NULL);
}

/**
 * _strcat - Append one string to another.
 * @dest: The destination buffer where the strings are concatenated.
 * @src: The source buffer that is appended to dest.
 *
 * Return: A pointer to the destination buffer.
 */
char *_strcat(char *dest, const char *src)
{
	return (strcat(dest, src));
}

int main(void)
{
	return (0);
}
