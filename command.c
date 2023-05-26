#include "shell.h"

/**
 * malloc_char - short description
 *
 * Description: long description
 *
 * @string: reference to string
 * @size_of_malloc: int size of malloc
 * @mms: string error message
 *
 * Return: return description
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
 * malloc_array - short description
 *
 * Description: long description
 *
 * @array: reference to string
 * @size_of_malloc: int size of malloc
 * @mms: string error message
 *
 * Return: return description
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
 * c_array - short description
 *
 * Description: long description
 *
 * @dest: argument_1 description
 * @source: argument_2 description
 *
 * Return: return description
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
 * envname_ - short description
 *
 * Description: long description
 *
 * @name: name string
 *
 * Return: return description
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
 * _block - short description
 *
 * Description: long description
 *
 * Return: return description
 */
int _block(void)
{
	unsigned int q;

	for (q = 0; __environ[q]; q++);

	return (q);
}
