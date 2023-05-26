#include "shell.h"

/**
 * isbuilt - handles builtin
 * @a: command array
 * Return: 1 if success 0 if failure
 */
int isbuilt(char **a)
{
	int e;
	const struct builtin_command built[] = {
		{"env", _printsenv},
		{"exit", exitbuilt},
		{NULL, NULL}
	};

	if (a == NULL)
		return (0);
	if (a[0] == NULL)
		return (0);

	for (e = 0; built[e].name != NULL;
			e++)
		if (strcmp(a[0],
					built[e].name) == 0)
			return (1);
	return (0);
}

/**
 * _handler - handles built command
 * @a: command array
 * Return: 1 if success 0 if failure
 */
int _handler(char **a)
{
	int e;
	const struct builtin_command built[] = {
		{"env", _printsenv},
		{"exit", exitbuilt},
		{NULL, NULL}
	};

	if (a == NULL)
		return (0);
	if (a[0] == NULL)
		return (0);

	for (e = 0; built[e].name != NULL;
			e++)
	{
		if (strcmp(a[0],
					built[e].name) == 0)
			return (built[e].function(a));
	}
	return (0);
}
