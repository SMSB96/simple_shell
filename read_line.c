#include "shell.h"

/**
 * read_user_input - Read user input from stdin.
 *
 * Return: The user input as a string or NULL on error.
 */
char *read_user_input(void)
{
<<<<<<< HEAD
	size_t len = 0;
	char *line = NULL;
	size_t n;
=======
	ssize_t bytes;
	char *input = NULL;
	size_t buffer_size = 0;

>>>>>>> fe98b16715c3bed1c9c28981f4e341e3052c0c77
	write(STDOUT_FILENO, "$ ", 2);
	bytes = getline(&input, &buffer_size, stdin);
	if (bytes == -1)
	{
		
		free(input);
		return (NULL);
	} 
	
	return (input);
}
