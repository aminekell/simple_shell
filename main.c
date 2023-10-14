#include "shell.h"
/**
* main - Simple Shell main function
* @ac: Count of argumnents
* @av: Arguments
* Return: Always (success).
*/  
int main(int ac, char **av)
{
    char *line = NULL, **command = NULL;
    int status = 0;
    (void) ac;

    while (1)
    {
        line = read_line();
        if (line == NULL) /* reached EOF, Ctrl + D */
        {
            if (isatty(STDIN_FILENO))
            {
                write(STDOUT_FILENO, "\n", 1);
            }
            return (status);
        }

        command = tokenizer(line);
        if (!command)
              continue;
        status = _execute(command, av);
    }

}


