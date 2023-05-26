#include "shell.h"

void my_exit(const char *status)
{
char *endptr;
int exit_status = strtol(status, &endptr, 10);

if (*endptr != '\0')
{
fprintf(stderr, "Invalid exit status: %s\n", status);
exit(1);
}
exit(exit_status);
}

int _statuss(int argc, char *argv[])
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
    else if (argc > 1 && strcmp(argv[1], "status") == 0)
    {
        if (argc > 2)
        {
            int exit_status = atoi(argv[2]);
            exit(exit_status);
        }
        else
        {
            fprintf(stderr, "Usage: status <exit_status>\n");
            exit(1);
        }
    }
    else if (argc > 1 && strcmp(argv[1], "fail") == 0)
    {
        fprintf(stderr, "Command failed.\n");
        exit(1);
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

int mark(int argc, char *argv[])
{
return _statuss(argc, argv);
}
