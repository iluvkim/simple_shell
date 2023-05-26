#include "shell.h"

void execute_command(const char *cmd)
{
	int exit_status = system(cmd);

	if (exit_status == -1)
	{
		perror("Error executing command");
	} else
	{
		printf("Command executed with exit status: %d\n", exit_status);
	}
}

int _cndd(int argc, char *argv[])
{
	const char *filename;
	FILE *file;

	if (argc != 2)
	{
		fprintf(stderr, "Usage: %s [filename]\n", argv[0]);
		return (1);
	}

	filename = argv[1];
	file = fopen(filename, "r");
	if (file == NULL)
	{
		perror("Error opening file");
		return (1);
	}

	for (;;)
	{
		char command[MAX_COMMAND_LENGTH];

		if (fgets(command, sizeof(command), file) == NULL)
			break;

		command[strcspn(command, "\n")] = '\0';

		execute_command(command);
	}

	fclose(file);

	return (0);
}
