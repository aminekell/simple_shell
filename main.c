#include "shell.h"
int main(void)
{
char *line = NULL, **alternative_command = NULL;
char *path = getenv("PATH");
int alternative_status = 0;
char *original_path = strdup(path);
int i;
while (1) 
{
pid_t child_pid;
if (isatty(STDIN_FILENO))
{
printf("$ ");
fflush(stdout); }
line = custom_read_line();
if (line == NULL) 
{
if (isatty(STDIN_FILENO))
{
printf("\n"); }
free(original_path);
return alternative_status; }
alternative_command = my_tokenizer(line);
if (!alternative_command)
{
free(line);
continue;}
if (strcmp(alternative_command[0],"exit") == 0)
{
free(line);
free(original_path);
for (i = 0; alternative_command[i] != NULL; i++)
{
free(alternative_command[i]);  }
free(alternative_command);
exit(alternative_status);  }
child_pid = fork();
if (child_pid == -1)
{
perror("fork");
free(line);
free(original_path);
for (i = 0; alternative_command[i] != NULL; i++)
{
free(alternative_command[i]); }
free(alternative_command);
exit(EXIT_FAILURE); }
if (child_pid == 0)
{
setenv("PATH", original_path, 1) ;
if (execvp(alternative_command[0], alternative_command) == -1)
{
fprintf(stderr,"%s: 1: %s: not found\n","./hsh",alternative_command[0]) ;
free(line) ;
free(original_path) ;
for (i = 0; alternative_command[i] != NULL; i++)
{
free(alternative_command[i]) ; }
free(alternative_command) ;
exit(127); }
if (strcmp(alternative_command[0], "env") == 0)
{
execvp("env", alternative_command) ;
perror("execvp") ;
exit(1) ; }
} else
{
int status;
wait(&status) ;
if (WIFEXITED(status))
{
alternative_status = WEXITSTATUS(status); }
else
{
alternative_status = -1; }
for (i = 0; alternative_command[i] != NULL; i++)
{
free(alternative_command[i]); }
free(alternative_command) ;
free(line); } }
return 0; }
