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
	char *dir_cpy;

	for (u = 0; __environ[u]; u++)
	{
		if (strncmp(__environ[u], name, strlen(name)) == 0)
		{
			envar_length = strlen(__environ[u]) - strlen(name);
			dir = malloc(sizeof(char) * envar_length);
			if (dir == NULL)
			{
				perror("_getenv() Error: dir malloc failed");
				return (NULL);
			}

			dir = malloc(sizeof(char) * (envar_length + 1));
			if (dir_cpy == NULL)
				{
				perror("_getenv() Error: dir_cpy malloc failed");
				free(dir);
				return NULL;
			}

			malloc_char(&dir, strlen(__environ[u]) + 1, "_getenv() malloc error");
			strcpy(dir_cpy, __environ[u]);
			strncpy(dir, dir_cpy + strlen(name) + 1, envar_length);
			free(dir_cpy); /* Free dir_cpy after its use*/
			return (dir);
		}
	}

	return (NULL);
}

/**
 * _getLine
 * @istr: string
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
