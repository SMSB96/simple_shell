#include "shell.h"

/**
 * count_tokens - Count the number of tokens in a string.
 *
 * @line: The string to count tokens from.
 *
 * Return: The number of tokens or -1 on failure.
 */
static int count_tokens(char *line)
{
	char *token = NULL, *tmp = NULL;
	int token_count = 0;

	if (!line)
		return (-1);
	tmp = strdup(line);
	token = strtok(tmp, DELIM);

	while (token)
	{
		token_count++;
		token = strtok(NULL, DELIM);
	}

	free(tmp);
	return (token_count);
}

/**
 * allocate_tokens - Allocate memory for an array of tokens.
 *
 * @token_count: The number of tokens to allocate space for.
 *
 * Return: An array of tokens or NULL on failure.
 */
static char **allocate_tokens(int token_count)
{
	return (malloc(sizeof(char *) * (token_count + 1)));
}

/**
 * copy_tokens - Copy tokens from the input string to the allocated array.
 *
 * @line: The string to tokenize and copy.
 * @command: The array to store the tokens.
 *
 * Return: 0 on success, -1 on failure.
 */
static int copy_tokens(char *line, char **command)
{
	char *token = NULL;
	int i = 0;

	token = strtok(line, DELIM);

	while (token)
	{
		command[i] = strdup(token);

		if (!command[i])
		{

			return (-1);
		}

		token = strtok(NULL, DELIM);
		i++;
	}

	command[i] = NULL;
	return (0);
}

/**
 * tokenize_line - Tokenize a string.
 *
 * @line: The string to tokenize.
 *
 * Return: An array of tokens or NULL on failure.
 */
char **tokenize_line(char *line)
{
	char **command = NULL;
	int token_count = 0;

	if (!line)
		return (NULL);

	token_count = count_tokens(line);

	if (token_count == -1)
	{
		free(line);
		return (NULL);
	}

	command = allocate_tokens(token_count);

	if (!command)
	{
		free(line);
		return (NULL);
	}

	if (copy_tokens(line, command) == -1)
	{

		free_2d_array(command);
		return (NULL);
	}

	free(line);
	return (command);
}

