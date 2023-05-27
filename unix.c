#include "shell.h"

/**
 * forks_thread - Fork a child process and execute a command
 * @s: String command to execute
 * @a: Array of arguments for the command
 * Returns: 0 on success or -1 on failure.
 */
int forks_thread(char *s, char **a)
{
	pid_t pid;
	int status, is_execve_error;

	pid = fork();
	if (pid == -1)
	{
		perror("_fork() Error: fork child unable to create");
		return (-1);
	}
	if (pid == 0)
	{
		is_execve_error = execve(s, a, __environ);
		if (is_execve_error == -1)
		{
			perror("execve: ");
			return (-1);
		}
	}
	else
	{
		wait(&status);
		free(s);
		if (WIFEXITED(status))
			status = WEXITSTATUS(status);
		if (!isatty(STDIN_FILENO))
			return (status);
	}
	return (0);
}
