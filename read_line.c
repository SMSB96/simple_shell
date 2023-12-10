#include "shell.h"

/**
 * read_line - Read user input from stdin.
 *
 * Return: The line as a string or NULL on error.
 */
char *read_line(void)
{
	ssize_t len = 0;
	char *line = NULL;
	size_t n;
	write(STDOUT_FILENO, "$ ", 2);
	n = getline(&line, &len, stdin);
	if (n == -1)
	{
		
		free(input);
		return (NULL);
	} 
	
	return (line);
}
