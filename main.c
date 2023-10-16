#include "shell.h"
/**
* main - Simple Shell main function
* @ac: Count of argumnents
* @av: Arguments
* Return: Always (success).
*/ 
int main(int ac, char **av)
{
	char *line = NULL, **alternative_command = NULL;
	int alternative_status = 0;
	(void) ac;

	while (1)
	{
	if (isatty(STDIN_FILENO))
	{
		printf("$ ");
		fflush(stdout);
	}
	line = custom_read_line();
	if (line == NULL)
	{
		if (isatty(STDIN_FILENO))
		{
			printf("\n");
		}
		return (alternative_status);
	}
	alternative_command = my_tokenizer(line);

	if (!alternative_command)
		continue;
	alternative_status = execute_alternative(alternative_command, av);
	}
}
