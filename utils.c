#include "shell.h"

/**
 * parse_input - Splits the user input into arguments
 * @input: The input string
 *
 * Return: An array of arguments
 */

char **parse_input(char *input)
{
	char **args = NULL;
	char *token = NULL;
	size_t i = 0;

	args = malloc(64 * sizeof(char *));
	if (!args)
	{
		perror("malloc");
		return (NULL);
	}

	token = strtok(input, " ");
	while (token)
	{
		args[i++] = strdup(token);
		token = strtok(NULL, " ");
	}
	args[i] = NULL;
	return (args);
}

/**
 * free_args - Frees the memory allocated for arguments
 * @args: The array of arguments
 */

void free_args(char **args)
{
	size_t i = 0;

	if (!args)
	return;

	while (args[i])
	free(args[i++]);
	free(args);
}
