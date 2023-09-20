#include "shell.h"
#include <stdlib.h>
#include <string.h>
/**
 * add_node - inserts a node at the beginning of the list
 * @head: pointer address to head node
 * @str: str field of node
 * @num: node index utilized by history
 *
 * Return: size of list
 */
list_t *add_node(list_t **head, const char *str, int num)
{
	if (!head)
		return (NULL);

	list_t *new_head = (list_t *)malloc(sizeof(list_t));

	if (!new_head)

		return (NULL);

	new_head->num = num;
	new_head->str = (str) ? strdup(str) : NULL;

	new_head->next = *head;
	*head = new_head;

	return (new_head);
}
/**
 * add_node_end - insterts node to the end of list
 * @head: pointer address to head node
 * @str: node str field
 * @num: node index utilized by history
 *
 * Return: list size
 */
list_t *add_node_end(list_t **head, const char *str, int num)
{
	if (!head)
		return (NULL);
	list_t *new_node = (list_t *)malloc(sizeof(list_t));

	if (!new_node)

		return (NULL);
	new_node->num = num;
	new_node->str = (str) ? strdup(str) : NULL;
	new_node->next = NULL;

	if (!*head)
		*head = new_node;
	else
	{
		list_t *node = *head;

		while (node->next)

		node = node->next;
		node->next = new_node;
	}
	return (new_node);
}
/**
 * print_list_str - prints out the str element of a list_t linked list
 * @h: first node pointer
 *
 * Return: list size
 */
size_t print_list_str(const list_t *h)
{
	size_t i = 0;

	while (h)

	{
		_puts((h->str) ? h->str : "(nil)");
		_puts("\n");
		h = h->next;
		i++;
	}
	return (i);
}
/**
 * delete_node_at_index - it deletes the node at the specified index
 * @head: address of pointer to first node
 * @index: index of node to delete
 *
 * Return: 1 on success, 0 on failure
 */
int delete_node_at_index(list_t **head, unsigned int index)
{
	if (!head || !*head)
		return (0);
	if (index == 0)
	{
		list_t *node = *head;
		*head = (*head)->next;
		free(node->str);
		free(node);
		return (1);
	}
	list_t *prev_node = NULL;
	list_t *node = *head;
	unsigned int i = 0;

	while (node)

	{
		if (i == index)
		{
			prev_node->next = node->next;
			free(node->str);
			free(node);
			return (1);
		}
		i++;
		prev_node = node;
		node = node->next;
	}
	return (0);
}
/**
 * free_list - frees all list nodes
 * @head_ptr: address of pointer to head node
 *
 * Return: void
 */
void free_list(list_t **head_ptr)
{
	if (!head_ptr || !*head_ptr)
		return;
	list_t *node = *head_ptr;

	while (node)

	{
		list_t *next_node = node->next;

		free(node->str);

		free(node);
		node = next_node;
	}
	*head_ptr = NULL;
}
