#include "shell.h"

/**
 * malloc_char - dynamically allocates memory for a char array
 * @string: pointer to the char array to be allocated
 * @size_of_malloc: size of memory to be allocated in bytes
 * @mms: error message to be displayed in case of allocation failure
 */
char *malloc_char(char **string, size_t size_of_malloc, char *mms)
{
	*string = (char *) malloc(sizeof(char) * size_of_malloc);
	if (string == NULL)
	{
		perror(mms);
		return (NULL);
	}
	return (*string);
}

/**
 * malloc_array - dynamically allocates memory for an array of char arrays
 * @array: pointer to the array to be allocated
 * @size_of_malloc: size of memory to be allocated in bytes
 * @mms: error message to be displayed in case of allocation failure
 */
char **malloc_array(char **array, size_t size_of_malloc, char *mms)
{
	array = (char **) malloc(sizeof(char *) * size_of_malloc);
	if (array == NULL)
	{
		perror(mms);
		return (NULL);
	}
	return (array);
}

/**
 * c_array - copies char arrays from source to destination array
 * @dest: pointer to the destination array
 * @pth: pointer to the source array
 */
int c_array(char **dest, char **pth)
{
	size_t v, w;

	for (v = 0; pth[v]; v++)
	{
		dest[v] = malloc(sizeof(char) *
				strlen(pth[v]));
		if (dest[v] == NULL)
		{
			perror("_setenv() Error: new_env[v] malloc failed");
			for (w = 0; w < v;
					w++)
				free(dest[v]);
			free(dest);
			return (-1);
		}
		strcpy(dest[v], pth[v]);
	}
	return (0);
}

/**
 * envname_ - searches for an environment variable name in __environ array
 * @name: name of the environment variable to search for
 */
int envname_(const char *name)
{
	int u, f;

	f = -1;
	for (u = 0; __environ[u]; u++)
		if (strncmp(__environ[u], name, strlen(name)) == 0)
			f = u;
	return (f);
}

/**
 * _block - Count the number of environment variables
 *
 * Return: The number of environment variables
 */
int _block(void)
{
unsigned int q = 0;

while (__environ[q] != NULL)
q++;

return (q);
}
