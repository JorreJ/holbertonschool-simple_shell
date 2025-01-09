#include "simple_shell.h"

/**
 * parse_input - Splits the user input into arguments
 * @string: The input string
 *
 * Return: An array of arguments
 */

char **parse_input(char *string)
{
	char **args = NULL;
	char *token = NULL;
	size_t i = 0;

	args = malloc(sizeof(char *) * 64); /* allocate memory */
	if (!args) /* handle malloc error */
		return (NULL);

	token = strtok(string, " \t\n"); /* tokenize the string */
	while (token && i < 64)
	{
		args[i++] = token;
		token = strtok(NULL, " \t\n");
	}
	args[i] = NULL;
	return (args);
}

/**
 * command_path - search the absolute path of the input command
 * @string: input command
 *
 * Return: string containing the absolute path of the command
 */

char *command_path(char *string)
{
	char *path = getenv("PATH"), *copy;
	char *token = NULL, *cmd_path = NULL;
	struct stat st;

	if (_strchr(string, '/') && stat(string, &st) == 0) /* check absolute path */
		return (string);
	if (!path) /* handle getenv error */
		return (NULL);
	copy = strdup(path); /* copy the env var took by getenv */
	token = strtok(copy, ":"); /* tokenize the copied env var */
	while (token) /* check all paths */
	{
		cmd_path = malloc((sizeof(char) * _strlen(token)) +
		(sizeof(char) * _strlen(string)) + 2);
		if (!cmd_path) /* handle malloc error */
			break;
		sprintf(cmd_path, "%s/%s", token, string); /* concatenate command and path */
		if (stat(cmd_path, &st) == 0) /* check if the path is correct */
		{
			free(copy);
			return (cmd_path);
		}
		free(cmd_path); /* free allocated memory */
		token = strtok(NULL, ":"); /* tokenize the copied env var */
	}
	free(copy);
	return (NULL);
}
