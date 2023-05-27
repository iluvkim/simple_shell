#include "shell.h"
#define si(signal, handler)

/**
 * _paint - entry point of the program
 * @ac: the number of command-line arguments
 * @arvs: array of command-line argument strings
 * @envp: array of environment variable strings
 * Return: The function returns 0.
 */
int _paint(__attribute((unused)) int ac,
		__attribute((unused)) char **arvs,
		__attribute((unused)) char **envp)
{
	int status = 0;
	char *istr, *delim, *which;
	size_t nummallocalloc, n;
	char **a;

	si(SIGINT, sigint_);
	istr = NULL;
	nummallocalloc = n = 0;
	delim = " \n";
	while (1)
	{
		n++;
		_getLine(&istr, &nummallocalloc, status);
		a = s_delim(istr, delim);
		if (!(*a))
			status = 0;
		else
		{
			if (isbuilt(a))
			{
				if (_handler(a) == EXIT_CODE)
				{
					ffree(a, istr);
					exit(status);
				}
			}
			else
			{
				which = _alai(a[0]);
				if (which !=  NULL)
					status = forks_thread(which, a);
				else
					status = p_error(arvs, a, n);
			}
		}
		ffree(a, istr);
		istr = NULL;
	}
	return (0);
}
