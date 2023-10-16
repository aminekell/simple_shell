#include "shell.h"

int main(int ac, char **av) {
    char *line = NULL, **alternative_command = NULL;
    int alternative_status = 0;
    (void) ac; /* Silence the unused argument warning */

    while (1) {
        if (isatty(STDIN_FILENO)) {
            printf("$ ");
            fflush(stdout);
        }

        line = custom_read_line();

        if (line == NULL) {
            /* Reached EOF, Ctrl + D */
            if (isatty(STDIN_FILENO)) {
                printf("\n");
            }
            return (alternative_status);
        }

        /* Tokenize the input line */
        alternative_command = my_tokenizer(line);

        if (!alternative_command) {
            continue;
        }

        /* Execute the alternative command */
        alternative_status = execute_alternative(alternative_command, av);
    }
}
