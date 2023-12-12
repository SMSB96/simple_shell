#include "shell.h"

/**
 * execute_command - Execute a command using execve.
 *
 * @cmd: The command to execute.
 * @args: The arguments for the command.
 *
 * Return: The exit status of the executed command.
 */
int execute_command(char **cmd, char **args)
{
    pid_t child_pid;
    int status;

    child_pid = fork();

    if (child_pid == 0)
    {
        if (execve(cmd[0], cmd, environ) == -1)
        {
            perror(args[0]);
            freearray2D(cmd);
            exit(100);
        }
    }
    else
    {
        waitpid(child_pid, &status, 0);
        freearray2D(cmd);
    }

    return WEXITSTATUS(status);
}

