#include "shell.h"

/**
 * execute_command - Executes a shell command in a child process.
 * @args: An array of arguments.
 * @front: A double pointer to the beginning of args.
 * Return: If an error occurs, the corresponding error code.
 *         Otherwise, the exit value of the last executed command.
 */
int execute_command(char **args, char **front)
{
	pid_t child_pid;
	int status, flag = 0, ret = 0;
	char *command = args[0];

	if (command[0] != '/' && command[0] != '.')
	{
		flag = 1;
		command = get_location(command);
	}

	if (!command || (access(command, F_OK) == -1))
	{
		ret = handle_command_error(args);
	}
	else
	{
		ret = execute_child_process(command, args, front, flag);
	}

	if (flag)
		free(command);

	return (ret);
}

/**
 * handle_command_error - Handles errors related to the command execution.
 * @args: An array of arguments.
 * Return: The corresponding error code.
 */
int handle_command_error(char **args)
{
	int ret;

	if (errno == EACCES)
		ret = create_error(args, 126);
	else
		ret = create_error(args, 127);

	return (ret);
}

/**
 * execute_child_process - Executes the command in a child process.
 * @command: The command to be executed.
 * @args: An array of arguments.
 * @front: A double pointer to the beginning of args.
 * @flag: A flag indicating whether the command was modified.
 * Return: The exit value of the last executed command.
 */
int execute_child_process(char *command, char **args, char **front, int flag)
{
	pid_t child_pid;
	int status, ret = 0;

	child_pid = fork();
	if (child_pid == -1)
	{
		if (flag)
			free(command);
		perror("Error child:");
		return (1);
	}

	if (child_pid == 0)
	{
		execute_child_code(command, args, front);
	}
	else
	{
		wait(&status);
		ret = WEXITSTATUS(status);
	}

	return (ret);
}

/**
 * execute_child_code - Code executed by the child process.
 * @command: The command to be executed.
 * @args: An array of arguments.
 * @front: A double pointer to the beginning of args.
 */
void execute_child_code(char *command, char **args, char **front)
{
	execve(command, args, environ);
	if (errno == EACCES)
		create_error(args, 126);

	free_env();
	free_args(args, front);
	free_alias_list(aliases);
	_exit(1);
}

