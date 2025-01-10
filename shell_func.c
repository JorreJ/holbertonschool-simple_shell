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
 * @env: environment var passed from main
 *
 * Return: string containing the absolute path of the command
 */

char *command_path(char *string, char **env)
{
	char *path = NULL, *copy, *token = NULL, *cmd_path = NULL;
	struct stat st;
	int i = 0;

	if (_strchr(string, '/') && stat(string, &st) == 0) /* check absolute path */
		return (string);
	while (env[i++] && _strcmp(env[i], "PATH=") != 0) /* get PATH env var */
	{
		if (_strcmp(env[i + 1], "PATH=") == 0)
			path = env[i + 1] + 5;
	}
	if (!path) /* handle getenv error */
	{
		perror("Path not found");
		return (NULL);
	}
	copy = strdup(path); /* copy the env var took by getenv */
	token = strtok(copy, ":"); /* tokenize the copied env var */
	while (token) /* check all paths */
	{
		cmd_path = malloc((_strlen(token)) + _strlen(string) + 2);
		if (!cmd_path) /* handle malloc error */
		{
			free(copy);
			exit(EXIT_FAILURE);
		}
		sprintf(cmd_path, "%s/%s", token, string); /* concatenate command and path */
		if (stat(cmd_path, &st) == 0 && access(cmd_path, X_OK) == 0) /* check if the path is correct */
		{
			free(copy);
			return (cmd_path);
		}
		free(cmd_path); /* free allocated memory */
		token = strtok(NULL, ":"); /* tokenize the copied env var */
	}
	free(copy);
	fprintf(stderr, "Command not found: %s\n", string);
	return (NULL);
}
