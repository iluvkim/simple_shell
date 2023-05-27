#include "shell.h"

/**
 * _tokennum - function that  returns the number of tokens in a str
 * @istr: input string
 * @delim: delimiter string
 * Return: -1 if failure
 */
size_t _tokennum(char *istr, char *delim)
{
	char *token;
	size_t t;

	t = 0;
	token = strtok(istr, delim);
	while (token != NULL)
	{
		t++;
		token = strtok(NULL, delim);
	}
	return (t);
}
/**
 * s_delim - function creates a NULL terminated array of a string delim
 * @istr: input string
 * @delim: delimiter string
 * Return: returns NULL on failure and the array on success
 */
char **s_delim(char *istr, char *delim)
{
	char *istr_cpy, *token;
	char **a;
	size_t t, y, token_free_index;

	a = NULL;
	malloc_char(&istr_cpy, strlen(istr) + 1,
			"s_delim() Error: istr_cpy maoloc failure");
	strcpy(istr_cpy, istr);
	t = _tokennum(istr_cpy, delim);
	a = malloc_array(a, t + 1,
			"s_delim() Error: a** maoloc failure");
	strcpy(istr_cpy, istr);
	token = strtok(istr_cpy, delim);
	for (y = 0; y < t; y++)
	{
		a[y] = (char *) malloc(sizeof(char) *
				strlen(token) + 1);
		if (a[y] == NULL)
		{
			for (token_free_index = 0;
					token_free_index < y;
					token_free_index++)
				free(a[token_free_index]);
			free(istr_cpy);
			free(a);
			perror("s_delim() Error: a maoloc failure");
			return (NULL);
		}
		strcpy(a[y], token);
		token = strtok(NULL, delim);
	}
	free(istr_cpy);
	a[t] = NULL;
	return (a);
}

/**
 * d_count - counts the digit
 * @n: the number to be counted
 * Return: the number of digits in the given number
 */
int d_count(size_t n)
{
	int d = 0;

	if (n == 0)
		return (1);
	while (n != 0)
	{
		n /= 10;
		d++;
	}

	return (d);
}
