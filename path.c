#include "shell.h"

/**
 * sigint_handler - signal handler for SIGINT
 * @si: signal
 * Return: nothing
 */
void sigint_(int si)
{
	if (si == SIGINT)
	{
		write(STDOUT_FILENO, "\n", 1);
		inter_mode();
		fflush(stdout);
	}
}

/**
 * _unsetenv - unset an environment variable
 * @name: name of the environment variable to unset
 * Returns: 0 on success or -1 on failure.
 */
int _unsetenv(const char *name)
{
	unsigned int u;
	int v, w, f;
	char **new_env;

	new_env = NULL;
	u = _block();
	f = envname_(name);
	if (f != -1)
	{
		new_env = malloc_array(new_env, u,
				"_unsetenv() Error: new_env malloc failed");
		for (v = 0; __environ[v]; v++)
		{
			if (v != f)
			{
				new_env[v] = malloc(sizeof(char) *
						strlen(__environ[v]));
				if (new_env[v] == NULL)
				{
					perror("_unsetenv() Error: new_env[v] malloc failed");
					for (w = 0; w < v;
							w++)
						free(new_env[v]);
					free(new_env);
					return (-1);
				}
				strcpy(new_env[v], __environ[v]);
			}
		}
		new_env[u] = NULL;
		__environ = new_env;
	}
	return (0);
}
