#include "shell.h"

/**
 * find_command - Finds the full path of a command
 * @command: The command to find
 *
 * Return: The full path of the command or NULL if not found
 */

char *find_command(char *command)
{
	char *path = getenv("PATH");
	char *token = NULL, *cmd_path = NULL;
	struct stat st;

	if (!path)
	return (NULL);

	token = strtok(path, ":");
	while (token)
	{
		cmd_path = malloc(strlen(token) + strlen(command) + 2);
		if (!cmd_path)
		return (NULL);

		sprintf(cmd_path, "%s/%s", token, command);
		if (stat(cmd_path, &st) == 0)
		return (cmd_path);

		free(cmd_path);
		token = strtok(NULL, ":");
	}
	return (NULL);
}
