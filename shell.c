#include "shell.h"

/**
 * main - simple shell
 * @ac: Count of arguments
 * @argv: Arguments
 * Return: success or error message.
 */
int main(int ac, char **argv)
{
	char *line = NULL;
	char **command = NULL;
	int status = 0;
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
	command = tokenize_line(line);
	if (!command)
	continue;

	status = execute_command(command, argv);

	return (0);
	}
}
