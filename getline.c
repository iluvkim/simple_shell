#include "shell.h"

/**
 * _getenv - Get the value of an environment variable
 * @name: The name of the environment variable.
 * Return: The value of the environment variable, or NULL if not found.
 */
char *_getenv(const char *name)
{
	unsigned int u, envar_length;
	char *dir;

	for (u = 0; __environ[u]; u++)
	{
		if (strncmp(__environ[u], name, strlen(name)) == 0)
		{
			envar_length = strlen(__environ[u]) - strlen(name) - 1;
			dir = malloc(sizeof(char) * (envar_length + 1));
			if (dir == NULL)
			{
				perror("_getenv() Error: dir malloc failed");
				return (NULL);
			}

			strcpy(dir, __environ[u] + strlen(name) + 1);
			return (dir);
		}
	}

	return (NULL);
}

/**
 * _getLine - reads a line from input and stores it in a string
 * @istr: pointer to the string to store the line read from input
 * @nummallocalloc: pointer to the size of allocated memory for the string
 * @status: the exit status
 * Return: -1 on failure greater than 0 on success
 */
ssize_t _getLine(char **istr,
		size_t *nummallocalloc, int status)
{
	ssize_t r;

	inter_mode();
	r = getline(istr,
			nummallocalloc, stdin);
	if (r == -1)
	{
		free(*istr);
		if (isatty(STDIN_FILENO))
			write(STDOUT_FILENO, "\n", strlen("\n"));
		exit(status);
	}
	return (r);
}
