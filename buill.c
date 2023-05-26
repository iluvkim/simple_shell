#include "shell.h"

void my_exit(const char *status)
{
    int exit_status = atoi(status);

    if (exit_status != 0 || strcmp(status, "0") == 0)
    {
        exit(exit_status);
    }
    else
    {
        fprintf(stderr, "Invalid exit status: %s\n", status);
        exit(1);
    }
}

int mark(int argc, char *argv[])
{
	int num;
    if (argc > 1 && strcmp(argv[1], "exit") == 0)
    {
        if (argc > 2)
        {
            my_exit(argv[2]);
        }
        else
        {
            fprintf(stderr, "Usage: exit status\n");
            exit(1);
        }
    }
    else if (argc > 1 && strcmp(argv[1], "fail") == 0)
    {
        fprintf(stderr, "Command failed.\n");
        exit(1);
    }
    else if (argc > 1 && strcmp(argv[1], "negative") == 0)
    {
        my_exit("-5");
    }
    else if (argc > 1 && strcmp(argv[1], "string") == 0)
    {
        my_exit("SomeString");
    }
    else
    {
        printf("my shell script.\n");

        num = 6;
        while (num > 0)
        {
            printf("long Loop: %d\n", num);
            num--;
        }
    }

    return 0;
}
