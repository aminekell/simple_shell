#include "shell.h"
<<<<<<< HEAD
int _execute (char **command, char **argv) 
{
int i;
pid_t child;
int status;
child = fork ();
if (child == 0)
{  
    if (execve (command[0], command, environ) == -1)
    { 
        perror (argv[0]);
        for (i = 0; command[i]; i++)
	{
		free (command[i]), command[i] = NULL;
	}
	free (command), command = NULL;
        exit (0);
    }
}
else
{
    waitpid (child, &status, 0);
        for (i = 0; command[i]; i++)
        {
               free (command[i]), command[i] = NULL;
        }
        free (command), command = NULL;
}
return (WEXITSTATUS(status));
}
=======

int _execute(char **command, char **argv)
{
    pid_t child;
    int status;
    child = fork();
    if (child == 0)
    {
        if (execve(command[0], command, environ) == -1)
        {
            perror(argv[0]);
            freearray2D(command);
	    exit(0);
        }
    }
    else
    {
        waitpid(child, &status, 0);
        freearray2D(command);
    }
return(WEXITSTATUS(status));

}


>>>>>>> 8f746d441f861bc0e7f9ed94c73a13750ee1a405
