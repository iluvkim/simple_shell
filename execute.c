#include "shell.h"

/**
 * freeslist - frees a listtoken_t list
 * @head: points to a pointer that points to the first node
 * Return: void
 */
void freeslist(listtoken_t **head)
{
	listtoken_t *node;

	if (head == NULL)
		return;

	while (*head != NULL)
	{
		node = *head;
		*head = node->next;
		free(node->token);
		free(node);
	}
	head = NULL;
}


/**
 * p_element - prints all the elements of a listtoken_t list
 * @head: points to the first node
 * Return: the number of nodes
 */
size_t p_element(const listtoken_t *head)
{
	int count = 0;
	const listtoken_t *y;

	if (head == NULL)
		return (0);

	y = head;
	while (y != NULL)
	{
		printf("%s\n", y->token);
		count++;

		y = y->next;
	}

	return (count);
}

/**
 * inter_mode
 * Return: -1 on failure greater than 0 on success
 */
void inter_mode(void)
{
	if (isatty(STDIN_FILENO))
		write(STDOUT_FILENO, "$ ", strlen("$ "));
}
