#include "shell.h"

int main(int ac, char **av) {
    char *line = NULL, **alternative_command = NULL;
    int alternative_status = 0;
    (void) ac;

    while (1) {
        if (isatty(STDIN_FILENO)) {
            printf("$ ");
            fflush(stdout);
        }

        line = custom_read_line();
        
        if (line == NULL) { /* reached EOF, Ctrl + D */
            if (isatty(STDIN_FILENO)) {
                printf("\n");
            }
            return (alternative_status);
        }

      alternative_command = tokenizer(line);

        if (!alternative_command) {
            continue;
        }

        alternative_status = alternative_execute(alternative_command, av);
    }
}
