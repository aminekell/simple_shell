#include "shell.h"
/**
* my_tokenizer - function the commands execute
* @input_line: commands argument
* Return: NULL or status
**/
char **my_tokenizer(char *input_line)
{
char *my_token = NULL, *temp = NULL;
char **command_array = NULL;
int count = 0, index = 0;
if (!input_line)
{
return (NULL);
}
/* Duplicate the input line */
temp = strdup(input_line);
/* Tokenize the duplicated line */
my_token = strtok(temp, DELIM);
if (my_token == NULL)
{
/* Free memory and return NULL if no tokens found */
input_line = NULL;
free(temp);
temp = NULL;
return (NULL); }
while (my_token)
{
count++;
my_token = strtok(NULL, DELIM); }
free(temp);
temp = NULL;
command_array = malloc(sizeof(char *) * (count + 1));
if (!command_array)
{
input_line = NULL;
return (NULL); }
my_token = strtok(input_line, DELIM);
while (my_token)
{
command_array[index] = strdup(my_token);
my_token = strtok(NULL, DELIM);
index++; }
input_line = NULL;
command_array[index] = NULL;
return (command_array); }
