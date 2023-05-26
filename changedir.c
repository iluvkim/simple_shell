#include "shell.h"

/**
 * exitbuilt - builtin exit
 * @a: command array
 * Return: 0 if failure 1 if sucess
 */
int exitbuilt(char **a)
{
	if (a[1] != NULL)
		exit(atoi(a[1]));
	else
		return (EXIT_CODE);
}

/**
 * ffree - free array of tokens in the main function
 * @a: tokenized string
 * @istr: string
 * Return: void
 */
void ffree(char **a, char *istr)
{
	int index;

	for (index = 0; a[index]; index++)
		free(a[index]);
	free(a);
	free(istr);
}

/**
 * wfree - est if current char in buffer
 */
void wfree(char **x, char **a)
{
	int index;

	if (a != NULL)
	{
		for (index = 0; a[index]; index++)
			if (a[index] != NULL)
				free(a[index]);
		free(a);
	}
	if (*x != NULL)
		free(*x);
}
