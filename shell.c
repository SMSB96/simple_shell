#include "shell.h"

int execute_command(char **args, char **front);
static void handle_interactive_mode(void);
static void handle_non_interactive_mode(void);

/**
 * sig_handler - Signal handler function for handling SIGINT.
 * @sig: The signal number.
 */
void sig_handler(int sig)
{
	char *new_prompt = "\n$ ";

	(void)sig;
	signal(SIGINT, sig_handler);
	write(STDIN_FILENO, new_prompt, 3);
}


/**
 * run_shell - Runs the shell, handling user input and executing commands.
 * @argc: The number of command-line arguments.
 * @argv: An array of strings representing the command-line arguments.
 * Return: The exit status of the shell.
 */
int run_shell(int argc, char *argv[])
{
	int ret = 0;
	int *exe_ret = &retn;

	name = argv[0];
	hist = 1;
	aliases = NULL;
	signal(SIGINT, sig_handler);

	*exe_ret = 0;
	environ = _copyenv();
	if (!environ)
		exit(-100);

	if (argc != 1)
	{
		ret = proc_file_commands(argv[1], exe_ret);
		free_env();
		free_alias_list(aliases);
		return (*exe_ret);
	}

	if (!isatty(STDIN_FILENO))
	{
		handle_non_interactive_mode();
	}
	else
	{
		handle_interactive_mode();
	}

	free_env();
	free_alias_list(aliases);
	return (*exe_ret);
}

/**
 * main - The main function of the shell program.
 * @argc: The number of command-line arguments.
 * @argv: An array of strings representing the command-line arguments.
 * Return: The exit status of the shell.
 */
int main(int argc, char *argv[])
{
	return (run_shell(argc, argv));
}

