#include "shell.h"

int is_integer(const char* str) {
    int i = 0;
    while (str[i] != '\0') {
        if (str[i] < '0' || str[i] > '9') {
            return 0;
        }
        i++;
    }
    return 1;
}

void exit_command(int argc, char* argv[]) {
    if (argc > 1) {
        if (is_integer(argv[1])) {
            int exit_status = atoi(argv[1]);
            exit(exit_status);
        } else {
            printf("Invalid exit status: status must be an integer.\n");
            exit(1);
        }
    } else {
        exit(0);
    }
}

int mark(int argc, char* argv[]) {
    if (argc > 1) {
        exit_command(argc, argv);
    } else {
        printf("No arguments provided.\n");
    }
    return 0;
}
