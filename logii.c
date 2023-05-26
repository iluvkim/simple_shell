#include "shell.h"

/**
 * _nodetoken - adds a new node at the end of a listtoken_t list
 * @head: points to a pointer that points to the first node
 * @token: the token to add
 * Return: the address of the new element, or NULL if it failed
 */
listtoken_t *_nodetoken(listtoken_t **head, char *token)
{
	listtoken_t *n_nodes, *l_nodes;

	if (head == NULL)
		return (NULL);

	n_nodes = malloc(sizeof(listtoken_t));
	if (n_nodes == NULL)
		return (NULL);

	n_nodes->token = token;
	n_nodes->token_length = strlen(token);
	n_nodes->next = NULL;

	if (*head == NULL)
		*head = n_nodes;
	else
	{
		l_nodes = *head;
		while (l_nodes->next != NULL)
			l_nodes = l_nodes->next;

		l_nodes->next = n_nodes;
	}

	return (l_nodes);
}

/**
 * _validpath
 * @filename: string
 * Return: 1 is executable 0 is non executable
 */
int _validpath(char *filename)
{
	size_t length = strlen(filename);

	if (length >= strlen("../"))
		if (strncmp(filename, "../", strlen("../")) == 0)
			return (1);
	if (length >= strlen("./"))
		if (strncmp(filename, "./", strlen("./")) == 0)
			return (1);
	if (length >= strlen("/"))
		if (strncmp(filename, "/", strlen("/")) == 0)
			return (1);
	return (0);
}

/**
 * filepath_
 * @filename: file name string
 * @y: index to copy
 * Return: void
 */
void filepath_(char **_path, char **a,
		char *filename, int y)
{
	*_path = malloc(strlen(a[y]) + strlen(filename) + 2);
if (*_path == NULL)
{
    perror("_alai Error: malloc failed for _path");
    exit(EXIT_FAILURE);
}
	strcpy(*_path, a[y]);
	strcat(*_path, "/");
	strcat(*_path, filename);
	strcat(*_path, "\0");
}

char *_alai(char *filename)
{
	struct stat sb;
	char *x, *delim, *_path;
	char **a;
	int y, i;

	delim = ":";
	x = _getenv("PATH");
	if (x != NULL)
	{
		a = s_delim(x, delim);
		if (a != NULL)
		{
			for (y = 0; a[y]; y++)
			{
				filepath_(&_path, a, filename, y);
				i = stat(_path, &sb);
				if (i == 0)
				{
					wfree(&x, a);
					return (_path);
				}
				free(_path);
			}
			wfree(&x, a);
		}
		else
			free(x);
	}
	i = stat(filename, &sb);
	if (i == 0 && _validpath(filename))
		return (strdup(filename));
	return (NULL);
}
