#include "shell.h"

/**
 * _printsenv - print enviroment
 * @a: command array
 * Return: 0 for failure 1 for Sucess
 */
int _printsenv(__attribute((unused)) char **a)
{
	int enviroment_index;

	for (enviroment_index = 0; __environ[enviroment_index]; enviroment_index++)
	{
		write(STDOUT_FILENO, __environ[enviroment_index],
				strlen(__environ[enviroment_index]));
		write(STDOUT_FILENO, "\n", strlen("\n"));
	}
	return (enviroment_index);
}

/**
 * p_error - Printing custom error for not found command
 * @arvs: command-line args
 * @a: tokenized array of strings
 * @n: counter
 * Return: void
 */
int p_error(char **arvs, char **a, size_t n)
{
	char *e;
	char *n_str = _convertstring(n);
	int size = (strlen(arvs[0]) + (2 * strlen(": ")) +
			d_count(n) + strlen(a[0]) +
			strlen(": not found\n") + 1);

    /*Allocate memory for e dynamically*/
	e = malloc(size);
	if (e == NULL)
	{
		perror("p_error Error: malloc error");
		free(n_str);
		return (-1);  /* Return an appropriate error code*/
	}

	strcpy(e, arvs[0]);
	strcat(e, ": ");
	strcat(e, n_str);
	strcat(e, ": ");
	strcat(e, a[0]);
	strcat(e, ": not found\n");
	strcat(e, "\0");

	write(STDERR_FILENO, e, strlen(e));

	free(e);  /* Only free if e was dynamically allocated*/
	free(n_str);
	return (127);
}
