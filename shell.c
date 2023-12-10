#include "shell.h"

/**
 * main - simple shell
 *@ac: Count of arguments
 *@av: Arguments
 * Return: success or error message.
 */
int main(int ac, char**argv)
{
	char *line = NULL;
	/*char **command = NULL;*/
	int status = 0;
	(void) ac;
	(void) argv;

	while(1)
	{
		line = read_line();
		if (line == NULL) /* ctr + D */
		{
			if (isatty(STDIN_FILENO))
				write(STDOUT_FILENO, "\n" , 1);
			return(status);
		}
		free(line);
		/*command = tokenizer(line);*/
		/*staus = _execute(command, argv);*/
	}
