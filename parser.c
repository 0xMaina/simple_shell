#include "shell.h"
#include <stdlib.h>  /* Added for malloc and free */
#include <string.h>  /* Added for strlen, strcpy, and strcmp */
#include <sys/stat.h>  /* Added for stat */

/**
 * is_cmd - finds out if a file is an executable command
 * @info: info struct
 * @path: file path
 *
 * Return: 1 if true, 0 otherwise
 */
int is_cmd(info_t *info, char *path)
{
	struct stat st;

	(void)info;

	if (!path || stat(path, &st))
		return (0);

	if (S_ISREG(st.st_mode))
		return (1);

	return (0);
}
/**
 * dup_chars - duplicates characters
 * @pathstr: the PATH string
 * @start: starting index
 * @stop: stopping index
 *
 * Return: new buffer pointer
 */
char *dup_chars(char *pathstr, int start, int stop)
{
	char *buf = NULL;
	int i = 0, k = 0;

	buf = (char *)malloc((stop - start + 1) * sizeof(char));
	if (!buf)
		return (NULL);

	for (k = 0, i = start; i < stop; i++)
	{
		if (pathstr[i] != ':')
			buf[k++] = pathstr[i];
	}
	buf[k] = '\0';
	return (buf);
}
/**
 * find_path - locates this cmd in the PATH string
 * @info: info struct
 * @pathstr: the PATH string
 * @cmd: the cmd to find
 *
 * Return: full path of cmd if found or NULL
 */
char *find_path(info_t *info, char *pathstr, char *cmd)
{
	int i = 0, curr_pos = 0;
	char *path = NULL;

	if (!pathstr)
		return (NULL);

	if (strlen(cmd) > 2 && starts_with(cmd, "./"))
	{
		if (is_cmd(info, cmd))
			return (cmd);
	}

	while (1)
	{
		if (!pathstr[i] || pathstr[i] == ':')
		{
			path = dup_chars(pathstr, curr_pos, i);
			if (!path)
				return (NULL);

			if (!*path)
				strcat(path, cmd);
				else
			{
				strcat(path, "/");
				strcat(path, cmd);
			}

			if (is_cmd(info, path))
				return (path);

			if (!pathstr[i])
				break;

			curr_pos = i;
		}
		i++;
	}
	return (NULL);
}
