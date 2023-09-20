#include "shell.h"
#include <stdlib.h>  /* Added for malloc and free */
#include <string.h>  /* Added for strlen, strcpy, and strcmp */
#include <stdio.h>   /* Added for printf */

/**
 * list_len - finds the length of a linked list
 * @h: first node pointer
 *
 * Return: list size
 */
size_t list_len(const list_t *h)
{
	size_t i = 0;

	while (h)
	{
		h = h->next;
		i++;
	}
	return (i);
}

/**
 * list_to_strings - gives an array of strings from list->str
 * @head: first node pointer
 *
 * Return: strings arrays
 */
char **list_to_strings(list_t *head)
{
	list_t *node = head;
	size_t i = list_len(head), j;
	char **strs;
	char *str;

	if (!head || !i)
		return (NULL);

	strs = (char **)malloc(sizeof(char *) * (i + 1));
	if (!strs)
		return (NULL);

	for (i = 0; node; node = node->next, i++)
	{
		str = (char *)malloc(strlen(node->str) + 1);
		if (!str)
		{
			for (j = 0; j < i; j++)
				free(strs[j]);
			free(strs);
			return (NULL);
		}

		strcpy(str, node->str);
		strs[i] = str;
	}
	strs[i] = NULL;
	return (strs);
}

/**
 * print_list - prints all elements of a list_t linked list
 * @h: first node pointer
 *
 * Return: list size
 */
size_t print_list(const list_t *h)
{
	size_t i = 0;

	while (h)
	{
		printf("%d: %s\n", h->num, (h->str) ? h->str : "(nil)");
		h = h->next;
		i++;
	}
	return (i);
}

/**
 * node_starts_with - returns a node whose string starts with a prefix
 * @node: list head pointer
 * @prefix: string to match
 * @c: character after the prefix to match
 *
 * Return: matched node or NULL
 */
list_t *node_starts_with(list_t *node, char *prefix, char c)
{
	char *p = NULL;

	while (node)
	{
		p = strstr(node->str, prefix);
		if (p == node->str && ((c == -1) || (p[strlen(prefix)] == c)))
			return (node);
		node = node->next;
	}
	return (NULL);
}

/**
 * get_node_index - gets node index
 * @head: list head pointer
 * @node: node pointer
 *
 * Return: index of the node or -1
 */
ssize_t get_node_index(list_t *head, list_t *node)
{
	size_t i = 0;

	while (head)
	{
		if (head == node)
			return (i);
		head = head->next;
		i++;
	}
	return (-1);
}
