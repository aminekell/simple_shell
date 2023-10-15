#include "shell.h"

int alternative_execute(char **alternative_command, char **alternative_argv) {
    int i;
    pid_t alternative_child;
    int alternative_status;

    alternative_child = fork();

    if (alternative_child == 0) {
        if (execve(alternative_command[0], alternative_command, environ) == -1) {
            perror(alternative_argv[0]);
            for (i = 0; alternative_command[i]; i++) {
                free(alternative_command[i]);
                alternative_command[i] = NULL;
            }
            free(alternative_command);
            alternative_command = NULL;
            exit(0);
        }
    } else {
        waitpid(alternative_child, &alternative_status, 0);
        for (i = 0; alternative_command[i]; i++) {
            free(alternative_command[i]);
            alternative_command[i] = NULL;
        }
        free(alternative_command);
        alternative_command = NULL;
    }
    return WEXITSTATUS(alternative_status);
}
