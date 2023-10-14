<<<<<<< HEAD
<<<<<<< HEAD:tokenizer.c
#include "shell.h"
char **tokenizer(char *line) {
    char *_strdup (const char *str);
    char *token = NULL, *tmp = NULL;
    char **command = NULL;
    int cpt = 0, i = 0;
    if (!line)
        return (NULL);
    tmp = _strdup(line);
    token = strtok(tmp, DELIM);

    while (token)
    {
        cpt++;
        token = strtok(NULL, DELIM);
    }
    free(tmp), tmp = NULL;
    command = malloc(sizeof(char *) * (cpt + 1));
    if (!command)
    {
        free(line), line = NULL;
        return (NULL);
    }
    token = strtok(line, DELIM);
    while (token)
    {
        command[i] = _strdup(token);
        token = strtok(NULL, DELIM);
        i++;
    }
    free(line), line = NULL;
    command[i] = NULL;
    return (command);
}
=======
=======
<<<<<<< HEAD:tokens.c
>>>>>>> 8e00e1c9db5782e2a9650ac78e3450bba631ae83
#include "shell.h"

char **tokenizer(char *line)
{
    char *token = NULL, *tmp = NULL;
    char **command = NULL;
    int cpt = 0, i = 0;
    if (!line)
        return (NULL);
    tmp = strdup(line);
    token = strtok(tmp, DELIM);
    if (token == NULL)
    {
         free(line), line = NULL;
          free(tmp), tmp = NULL;
          return NULL;
    }
    while (token)
    {
        cpt++;
        token = strtok(NULL, DELIM);
    }
    free(tmp), tmp = NULL;
    command = malloc(sizeof(char *) * (cpt + 1));
    if (!command)
    {
        free(line), line = NULL;
        return (NULL);
    }
    token = strtok(line, DELIM);
    while (token)
    {
        command[i] = strdup(token);
        token = strtok(NULL, DELIM);
        i++;
    }
    free(line), line = NULL;
    command[i] = NULL;
    return (command);
}

<<<<<<< HEAD
>>>>>>> bebe727e52a7f4f231bf361dca23e7423b7ae0c9:tokens.c
=======
=======
#include "shell.h"
char **tokenizer(char *line) {
    char *_strdup (const char *str);
    char *token = NULL, *tmp = NULL;
    char **command = NULL;
    int cpt = 0, i = 0;
    if (!line)
        return (NULL);
    tmp = _strdup(line);
    token = strtok(tmp, DELIM);

    while (token)
    {
        cpt++;
        token = strtok(NULL, DELIM);
    }
    free(tmp), tmp = NULL;
    command = malloc(sizeof(char *) * (cpt + 1));
    if (!command)
    {
        free(line), line = NULL;
        return (NULL);
    }
    token = strtok(line, DELIM);
    while (token)
    {
        command[i] = _strdup(token);
        token = strtok(NULL, DELIM);
        i++;
    }
    free(line), line = NULL;
    command[i] = NULL;
    return (command);
}
>>>>>>> 62f27a951ba3ce795671d8f64ac52cf975753e50:tokenizer.c
>>>>>>> 8e00e1c9db5782e2a9650ac78e3450bba631ae83
