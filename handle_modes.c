#include "shell.h"

/**
 * handle_interactive_mode - Handles the shell's interactive mode.
 */
static void handle_interactive_mode(void)
{
	while (1)
	{
		write(STDOUT_FILENO, "$ ", 2);
		int ret = handle_args(exe_ret);

		if (ret == END_OF_FILE || ret == EXIT)
		{
			if (ret == END_OF_FILE)
				write(STDOUT_FILENO, "\n", 1);
			free_env();
			free_alias_list(aliases);
			exit(*exe_ret);
		}
	}
}


/**
 * handle_non_interactive_mode - Handles the shell's non-interactive mode.
 */
static void handle_non_interactive_mode(void)
{
	int ret = 0;

	while (ret != END_OF_FILE && ret != EXIT)
		ret = handle_args(exe_ret);

	free_env();
	free_alias_list(aliases);
	exit(*exe_ret);
}
