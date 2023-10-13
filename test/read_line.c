#include "shell.h"

char *read_line(void)
{
    char *line = NULL;
    size_t buf_size = 0;

    /* قراءة سطر من المستخدم */
     if (getline(&line, &buf_size, stdin) == EOF) 
    {
      printf("\n");
      free(line);
      exit(EXIT_FAILURE);
    }
    return line;
}

