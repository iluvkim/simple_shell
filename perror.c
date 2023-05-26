#include "shell.h"

int print_node(void)
{
	unsigned int h;

	for (h = 0; __environ[h]; h++)
		printf("%s\n", __environ[h]);
	return (0);
}

/**
 * stringrevs - reverses a string
 * @str: the string
 * Return: void
 */
void stringrevs(char *str)
{
	int u, len;
	char tmp;

	len = 0;
	while (str[len] != '\0')
		len++;
	len--;
	for (u = 0; u < len; u++, len--)
	{
		tmp = str[u];
		str[u] = str[len];
		str[len] = tmp;
	}
}

/**
 * _convertstring - converts int to a string
 * @n: number to convert
 * Return: the converted integer
 */
char *_convertstring(size_t n)
{
	char *str = malloc(sizeof(char) * (32 + 1));
	int u = 0;

	do {
		str[u++] = n % 10 + '0';
		n /= 10;
	} while (n > 0);
	str[u] = '\0';
	stringrevs(str);

	return (str);
}
