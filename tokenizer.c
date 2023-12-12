#include "shell.h"

/**
 * tokenize_line - Tokenize a string.
 *
 * @line: The string to tokenize.
 *
 * Return: An array of tokens or NULL on failure.
 */
char **tokenize_line(char *line)
{
    char *token = NULL, *tmp = NULL;
    char **command = NULL;
    int token_count = 0, i = 0;

    if (!line)
        return (NULL);

    tmp = strdup(line);
    token = strtok(tmp, DELIM);

    if (token == NULL)
    {
        free(line);
        line = NULL;
        free(tmp);
        tmp = line;
        return (NULL);
    }

    while (token)
    {
        token_count++;
        token = strtok(NULL, DELIM);
    }

    free(tmp);
    tmp = NULL;

    command = malloc(sizeof(char *) * (token_count + 1));

    if (!command)
    {
        free(line);
        return (NULL);
    }

    token = strtok(line, DELIM);

    while (token)
    {
        command[i] = token;
        token = strtok(NULL, DELIM);
        i++;
    }

    free(line);
    line = NULL;
    command[i] = NULL;

    return (command);
}

