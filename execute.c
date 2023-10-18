#include "shell.h"
/**
 * execute_alternative - function for execute command
 * @commands: The first parameter
 * @arguments: the second parameter
 * Return: return status or NULL
*/
int execute_alternative(char **commands, char **arguments)
{
	int index;
	pid_t child_process;
	int status;

	child_process = fork();
	if (child_process == 0)
	{
		if (execve(commands[0], commands, environ) == -1)
		{
			perror(arguments[0]);
			for (index = 0; commands[index]; index++)
			{
				free(commands[index]), commands[index] = NULL;
			}
			free(commands), commands = NULL;
			exit(0);
		}
	}
	else
	{
		waitpid(child_process, &status, 0);
		for (index = 0; commands[index]; index++)
		{
			free(commands[index]);
			commands[index] = NULL;
		}
		free(commands);
		commands = NULL;
	}
	return (WEXITSTATUS(status));
}
