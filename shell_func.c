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
	size_t tok_num = 0;
	size_t len;
	size_t max_tok;

	if (!string)
		return (NULL);
	len = _strlen(string);
	max_tok = len / 2 + 1;
	args = malloc((max_tok + 1) * sizeof(char *)); /* allocate memory */
	if (!args) /* handle malloc error */
		return (NULL);
	token = strtok(string, " \t\n"); /* tokenize the string */
	while (token)
	{
		args[tok_num] = token;
		tok_num++;
		if (tok_num >= max_tok)
		{
			free(args);
			return (NULL);
		}
		token = strtok(NULL, " \t\n");
	}
	args[tok_num] = NULL;
	return (args);
}

/**
 * command_path - search the absolute path of the input command
 * @string: input command
 * @env: environment variable passed from main
 *
 * Return: string containing the absolute path of the command
 */

char *command_path(char *string, char **env)
{
	char *path, *copy, *token = NULL, *cmd_path = NULL;
	struct stat st;

	if (_strchr(string, '/')) /* check path */
	{
		if (stat(string, &st) == -1)
		{
			perror("Error checking file");
			return (NULL);
		}
		if (stat(string, &st) == 0 && S_ISREG(st.st_mode) && access(string, X_OK) == 0)
			return (strdup(string));
		return (NULL);
	}
	path = _getenv("PATH", env);
	if (!path)
		return (NULL);
	copy = strdup(path); /* copy the env var took by getenv */
	if (!copy)
		return (NULL);
	token = strtok(copy, ":"); /* tokenize the copied env var */
	while (token) /* check all paths */
	{
		cmd_path = malloc(_strlen(token) + _strlen(string) + 2);
		if (!cmd_path) /* handle malloc error */
		{
			free(copy);
			return (NULL);
		}
		sprintf(cmd_path, "%s/%s", token, string); /* concatenate command and path */
		if (stat(cmd_path, &st) == 0 && S_ISREG(st.st_mode) && access(cmd_path, X_OK) == 0) /* check path */
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

/**
 * _getenv - recover an environment variable
 * @name: name of the environment var to find.
 * @env: environment variable passed from main
 *
 * Return: Pointer to the value of the environment variable
 */

char *_getenv(const char *name, char **env)
{
	int i;
	size_t name_len;

	if (!name || !name[0])
		return (NULL);

	name_len = strlen(name);

	for (i = 0; env[i] != NULL; i++)
		if (strncmp(env[i], name, name_len) == 0 && (*env)[name_len] == '=')
			return (&((*env)[name_len + 1]));
	return (NULL);
}
