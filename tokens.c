#include "shell.h"

char **my_tokenizer(char *input_line) {
    char *my_token = NULL, *temp = NULL;
    char **command_array = NULL;
    int count = 0, index = 0;

    if (!input_line) {
        return (NULL);
    }

    /* Duplicate the input line */
    temp = strdup(input_line);

    /* Tokenize the duplicated line */
    my_token = strtok(temp, DELIM);

    if (my_token == NULL) {
        /* Free memory and return NULL if no tokens found */
        free(input_line);
        input_line = NULL;
        free(temp);
        temp = NULL;
        return NULL;
    }

    /* Count the number of tokens */
    while (my_token) {
        count++;
        my_token = strtok(NULL, DELIM);
    }

    /* Free the temporary copy */
    free(temp);
    temp = NULL;

    /* Allocate memory for the array of tokens */
    command_array = malloc(sizeof(char *) * (count + 1));

    if (!command_array) {
        /* Free memory and return NULL if allocation fails */
        free(input_line);
        input_line = NULL;
        return (NULL);
    }

    /* Tokenize the original line and store tokens in the array */
    my_token = strtok(input_line, DELIM);
    while (my_token) {
        command_array[index] = strdup(my_token);
        my_token = strtok(NULL, DELIM);
        index++;
    }

    /* Free the original line */
    free(input_line);
    input_line = NULL;

    /* Set the last element of the array to NULL */
    command_array[index] = NULL;
    return (command_array);
}

