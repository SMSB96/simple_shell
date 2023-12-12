#include "shell.h"

/**
 * main - simple shell
 * @ac: Count of arguments
 * @av: Arguments
 * Return: success or error message.
 */
int main(int ac, char **argv)
{
    char *line = NULL;
    char **command = NULL;
    int status = 0;
    int i;

    (void)ac;

    while (1)
    {
        line = read_line();
        if (line == NULL) /* ctrl + D */
        {
            if (isatty(STDIN_FILENO))
                write(STDOUT_FILENO, "\n", 1);
            return (status);
        }
        free(line);
        command = tokenizer(line);
        if (!command)
            continue;
        for (i = 0; command[i]; i++)
        {
            printf("%s\n", command[i]);
            free(command[i]);
            command[i] = NULL;
        }
        free(command);
        command = NULL;

        status = _execute(command, argv);
    }

    return (0);
}

