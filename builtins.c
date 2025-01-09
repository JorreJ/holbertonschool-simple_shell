#include "shell.h"

/**
 * handle_builtin - Handles built-in commands
 * @args: The array of arguments
 *
 * Return: 0 if a built-in command was executed, 1 otherwise
 */

int handle_builtin(char **args)
{
	if (strcmp(args[0], "exit") == 0)
	exit(0);
	else if (strcmp(args[0], "env") == 0)
	{
		for (int i = 0; environ[i]; i++)
		printf("%s\n", environ[i]);
		return (0);
	}
	return (1);
}
