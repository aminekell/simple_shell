#include "shell.h"

int main(void) {
    char *line = NULL, **alternative_command = NULL;
    char *path = getenv("PATH");
    int alternative_status = 0;

    char *original_path = strdup(path);

    int i;

    while (1) {
        pid_t child_pid;
        if (isatty(STDIN_FILENO)) {
            printf("$ ");
            fflush(stdout);
        }

        line = custom_read_line();

        if (line == NULL) {
            if (isatty(STDIN_FILENO)) {
                printf("\n");
            }
            free(original_path);
            return alternative_status;
        }

        alternative_command = my_tokenizer(line);
        if (!alternative_command) {
            free(line);
            continue;
        }

        child_pid = fork();

        if (child_pid == -1) {
            perror("fork");
            free(line);
            free(original_path);
            for (i = 0; alternative_command[i] != NULL; i++) {
                free(alternative_command[i]);
            }
            free(alternative_command);
            exit(EXIT_FAILURE);
        }

        if (child_pid == 0) {
            char command_path[1024];
            snprintf(command_path, sizeof(command_path), "/bin/ls/%s", alternative_command[0]);

            if (execvp(alternative_command[0], alternative_command) == -1) {
                perror("execv");
                free(line);
                free(original_path);
                for (i = 0; alternative_command[i] != NULL; i++) {
                    free(alternative_command[i]);
                }
                free(alternative_command);
                exit(EXIT_FAILURE);
            }
        } else {
            int status;
            wait(&status);

            if (WIFEXITED(status)) {
                alternative_status = WEXITSTATUS(status);
            } else {
                alternative_status = -1;
            }

            for (i = 0; alternative_command[i] != NULL; i++) {
                free(alternative_command[i]);
            }
            free(alternative_command);
            free(line);
        }
    }
}
