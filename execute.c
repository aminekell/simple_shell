#include "shell.h"
/**
* execute_alternative - function the commands execute
* @commands: commands argument
* @arguments: Arguments character
* Return: NULL or status
*/ 
int execute_alternative(char **commands, char **arguments)
{
	int index;
    pid_t child_process;
    int status;

    child_process = fork();

    if (child_process == 0) {
        /* Child process */
        if (execve(commands[0], commands, environ) == -1) {
            perror(arguments[0]);

            /* Free memory and exit */
            for (index = 0; commands[index]; index++) {
                free(commands[index]);
                commands[index] = NULL;
            }
            free(commands);
            commands = NULL;
            exit(0);
        }
    } else {
        /* Parent process */
        waitpid(child_process, &status, 0);

        /* Free memory */
        for (index = 0; commands[index]; index++) {
            free(commands[index]);
            commands[index] = NULL;
        }
        free(commands);
        commands = NULL;
    }
	return (WEXITSTATUS(status));
}
