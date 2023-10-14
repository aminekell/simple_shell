#include "shell.h"
<<<<<<< HEAD
/**
* main - Simple Shell main function
* @ac: Count of argumnents
* @av: Arguments
* Return: Always (success).
*/  
int main (int ac, char **argv) 
{
char *line = NULL, **command = NULL;
int  status = 0;
(void) ac;
while (1)
{
line = read_line ();
if (line == NULL)	/* reache EOF ctr + D */
{
        if (isatty(STDIN_FILENO))
                    write(STDOUT_FILENO, "\n", 1);
  	return (status);
}
command = tokenizer(line);
if (!command)
      continue;
status = _execute(command, argv);
 
=======

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
>>>>>>> 8f746d441f861bc0e7f9ed94c73a13750ee1a405
}
}

