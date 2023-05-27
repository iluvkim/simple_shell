#include "shell.h"

/**
 * c_envar - Create an environment variable string
 * @dir: Pointer to the resulting environment variable string
 * @envar_length: Length of the environment variable string
 * @name: Name of the environment variable
 * @value: Value of the environment variable
 */
void c_envar(char **dir, unsigned int envar_length, const char *name,
		const char *value)
{
	*dir = malloc_char(dir, envar_length,
			"_setenv() Error: dir malloc failed");
	envar_length = strlen(name) + strlen(value) + 2;
	*dir = malloc_char(dir, envar_length,
			"_setenv() Error: dir malloc failed");
	strcpy(*dir, name);
	strcat(*dir, "=");
	strcat(*dir, value);
	strcat(*dir, "\0");
}


/**
 * _envset - Set an environment variable
 * @dir: The environment variable string
 * @envar_length: Length of the environment variable string
 * @name: Name of the environment variable
 * @o: Overwrite flag (0: do not overwrite, non-zero: overwrite)
 * Return: 0 on success or -1 on failure.
 */
int _envset(char *dir, unsigned int envar_length, const char *name,
		int o)
{
	unsigned int u;

	for (u = 0; __environ[u]; u++)
	{
		if (strncmp(__environ[u], name, strlen(name)) == 0 && o != 0)
		{
			free(__environ[u]);
			__environ[u] = malloc(sizeof(char) * envar_length);
			if (__environ[u] == NULL)
			{
				perror("_setenv() Error: __environ[u] malloc failed");
				free(dir);
				return (-1);
			}
			strcpy(__environ[u], dir);
			free(dir);
			return (0);
		}
	}
	return (0);
}


/**
 * _envariable - Add an environment variable to the environment
 * @dir: The environment variable string
 * @envar_length: Length of the environment variable string
 * @q: Length of the existing environment variables
 * Return: 0 on success or -1 on failure
 */
int _envariable(char *dir, unsigned int envar_length,
		unsigned int q)
{
	unsigned int w;
	char **new_env;

	new_env = (char **) malloc(sizeof(char *) * (q + 2));
	if (new_env == NULL)
	{
		perror("_setenv() Error: new_env malloc failed");
		free(dir);
		return (-1);
	}
	c_array(new_env, __environ);
	new_env[q] = malloc(sizeof(char) * envar_length);
	if (new_env[q] == NULL)
	{
		perror("_setenv() Error: new_env[u] malloc failed");
		for (w = 0; w < q;
				w++)
			free(new_env[w]);
		free(new_env);
		free(dir);
		return (-1);
	}
	strcpy(new_env[q], dir);
	new_env[q + 1] = NULL;
	__environ = new_env;
	free(dir);
	return (0);
}

/**
 * _setenv - the setenv() function adds the variable name to the
 * @name: name string
 * @value: value string
 * @o: overwrite intger
 * Return: -1 on failure 0 on success
 */
int _setenv(const char *name, const char *value, int o)
{
	unsigned int envar_length;
	char *dir;

	envar_length = strlen(name) + strlen(value) + 2;
	c_envar(&dir, envar_length, name, value);
	_envset(dir, envar_length, name, o);
	if (envname_(name) != -1)
		_envset(dir, envar_length, name, o);
	else
		_envariable(dir, envar_length, _block());
	return (0);
}
