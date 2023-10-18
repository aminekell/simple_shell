#ifndef shell_h
#define shell_h
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <errno.h>
#include <fcntl.h>
#define DELIM " \t\n"
 
extern char **environ;
char *custom_read_line(void);
char **my_tokenizer(char *line);
int execute_alternative(char **alternative_command, char **argv);
#endif
