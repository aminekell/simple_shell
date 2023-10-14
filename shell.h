<<<<<<< HEAD
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

char *read_line(void);
char **tokenizer(char *line);
int _execute(char **command, char **argv);
#endif

=======
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

char *read_line (void);
char **tokenizer(char *line);
int _execute(char **command, char **argv);

char *_strdup (const char *str);
int _strcmp(char *s1, char *s2);
int _strlen(char  *s);
char *_strcat(char *dest, char *src);
char *_strcpy(char *dest, char *src);

void freearray2D(char **arr);


#endif
>>>>>>> 8f746d441f861bc0e7f9ed94c73a13750ee1a405
